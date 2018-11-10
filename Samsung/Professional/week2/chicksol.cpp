#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_R = 2000;
const int MAX_C = 200;
const int MAX_D = 200000;

int r, c;
int table[MAX_R][MAX_C];
int d;
pair<int, int> locs[MAX_D];

// row_sum[y][x] = table[y][0] + table[y][1] + ... + table[y][x]
int row_sum[MAX_R][MAX_C];
// dist[uy][0][yv][1] = minimum distance from table[uy][0] to table[vy][c - 1]
int dist[MAX_R][2][MAX_R][2];

// RowDist(y, x1, x2) returns
// table[y][x1] + table[y][x1 + 1] + ... + table[y][x2].
int RowDist(int y, int x1, int x2) {
  if (x1 > x2) {
    swap(x1, x2);
  }
  return (x1 == 0 ? row_sum[y][x2] : row_sum[y][x2] - row_sum[y][x1 - 1]);
}

int ReadInput() {
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> table[i][j];
    }
  }

  cin >> d;
  for (int i = 0; i < d; ++i) {
    int x, y;
    cin >> y >> x;
    locs[i] = make_pair(y - 1, x - 1);
  }
}

void ComputeRowSum() {
  for (int y = 0; y < r; ++y) {
    row_sum[y][0] = table[y][0];
    for (int x = 1; x < c; ++x) {
      row_sum[y][x] = row_sum[y][x - 1] + table[y][x];
    }
  }
}

// Computes distance between leftmost and rightmost cells in the same row,
// i.e., distance between (y, 1) and (y, c).
void ComputeMinDistInSameRow() {
  for (int y = 0; y < r; ++y) {
    dist[y][0][y][0] = table[y][0];
    dist[y][1][y][1] = table[y][c - 1];

    int min_dist = RowDist(y, 0, c - 1);
    int col_dist = 0;
    for (int y2 = y + 1; y2 < r; ++y2) {
      col_dist += table[y2 - 1][0] + table[y2 - 1][c - 1];
      min_dist = min(min_dist, col_dist + RowDist(y2, 0, c - 1));
    }
    col_dist = 0;
    for (int y2 = y - 1; y2 >= 0; --y2) {
      col_dist += table[y2 + 1][0] + table[y2 + 1][c - 1];
      min_dist = min(min_dist, col_dist + RowDist(y2, 0, c - 1));
    }
    dist[y][1][y][0] = dist[y][0][y][1] = min_dist;
  }
}

// Computes distance between any combination of leftmost and rightmost cells,
// i.e., (uy, 1) to (vy, 1), (uy, 1) to (vy, c), (uy, c) to (vy, 1),
// and (uy, c) to (vy, c).
void ComputeMinDist() {
  for (int uy = 0; uy < r; ++uy) {
    for (int ux = 0; ux < 2; ++ux) {
      for (int vy = uy + 1; vy < r; ++vy) {
        for (int vx = 0; vx < 2; ++vx) {
          dist[uy][ux][vy][vx] = dist[vy][vx][uy][ux] = min(
              dist[uy][ux][vy - 1][0] + dist[vy][0][vy][vx],
              dist[uy][ux][vy - 1][1] + dist[vy][1][vy][vx]);
        }
      }
    }
  }
}

int ComputeTotalDist() {
  int ux, uy, vx, vy;
  int64_t dist_sum = table[0][0];
  ux = uy = 0;
  for (int i = 0; i < d; ++i) {
    vy = locs[i].first;
    vx = locs[i].second;

    int dist_from_u_to_v = min(dist[uy][0][vy][0] - table[uy][0] - table[vy][0] + RowDist(uy, 0, ux) + RowDist(vy, 0, vx),
                                   dist[uy][0][vy][1] - table[uy][0] - table[vy][c - 1] + RowDist(uy, 0, ux) + RowDist(vy, vx, c - 1));
        dist_from_u_to_v = min(dist_from_u_to_v, dist[uy][1][vy][0] - table[uy][c - 1] - table[vy][0] + RowDist(uy, ux, c - 1) + RowDist(vy, 0, vx));
        dist_from_u_to_v = min(dist_from_u_to_v, dist[uy][1][vy][1] - table[uy][c - 1] - table[vy][c - 1] + RowDist(uy, ux, c - 1) + RowDist(vy, vx, c - 1));

    if (uy == vy) {
      dist_from_u_to_v = min(dist_from_u_to_v, RowDist(uy, ux, vx));
    }

    dist_sum += dist_from_u_to_v - table[uy][ux];

    
    ux = vx;
    uy = vy;
  }
  return dist_sum;
}

int main() {
  ReadInput();
  ComputeRowSum();
  ComputeMinDistInSameRow();
  ComputeMinDist();
  cout << ComputeTotalDist();
}