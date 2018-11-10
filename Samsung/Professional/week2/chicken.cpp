#include <cstdio>
#include <iostream>

using namespace std;

typedef struct locs
{
    int x;
    int y;
} _LOCS;

int R, C;
int D;
_LOCS LOCS[1005];

int TABLE[205][205];
int ROWSUM[205][205];
int DIST[205][2][205][2];

inline int min(int a, int b){ return a < b ? a : b; }

int rowDist(int y, int x1, int x2){
    if (x1 > x2){  int tmp = x1;  x1 = x2;  x2 = tmp;}
    return (x1 == 0 ? ROWSUM[y][x2] : ROWSUM[y][x2] - ROWSUM[y][x1 - 1]);
}

void calSameRow(){

    for (int y = 0; y < R; ++y) {
        DIST[y][0][y][0] = TABLE[y][0];
        DIST[y][1][y][1] = TABLE[y][C - 1];

        int min_dist = rowDist(y, 0, C - 1);
        int col_dist = 0;

        for (int y2 = y + 1; y2 < R; ++y2) {
            col_dist += TABLE[y2 - 1][0] + TABLE[y2 - 1][C - 1];
            min_dist = min(min_dist, col_dist + rowDist(y2, 0, C - 1));
        }

        col_dist = 0;

        for (int y2 = y - 1; y2 >= 0; --y2) {
            col_dist += TABLE[y2 + 1][0] + TABLE[y2 + 1][C - 1];
            min_dist = min(min_dist, col_dist + rowDist(y2, 0, C - 1));
        }

        DIST[y][1][y][0] = DIST[y][0][y][1] = min_dist;
    }
}


long long getResult()
{
    int ux, uy, vx, vy;
    long long dist_sum = TABLE[0][0];

    ux = uy = 0;

    for (int i = 0; i < D; ++i) {
        vy = LOCS[i].y;
        vx = LOCS[i].x;

        int dist_from_u_to_v = min(DIST[uy][0][vy][0] - TABLE[uy][0] - TABLE[vy][0] + rowDist(uy, 0, ux) + rowDist(vy, 0, vx),
                                   DIST[uy][0][vy][1] - TABLE[uy][0] - TABLE[vy][C - 1] + rowDist(uy, 0, ux) + rowDist(vy, vx, C - 1));
        dist_from_u_to_v = min(dist_from_u_to_v, DIST[uy][1][vy][0] - TABLE[uy][C - 1] - TABLE[vy][0] + rowDist(uy, ux, C - 1) + rowDist(vy, 0, vx));
        dist_from_u_to_v = min(dist_from_u_to_v, DIST[uy][1][vy][1] - TABLE[uy][C - 1] - TABLE[vy][C - 1] + rowDist(uy, ux, C - 1) + rowDist(vy, vx, C - 1));

        if (uy == vy) dist_from_u_to_v = min(dist_from_u_to_v, rowDist(uy, ux, vx));

        dist_sum += dist_from_u_to_v - TABLE[uy][ux];

        ux = vx;
        uy = vy;
    }

    return dist_sum;
}

int main()
{

    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            scanf("%d", &TABLE[i][j]);
        }
    }

    scanf("%d", &D);

    for (int i = 0; i < D; ++i) {
        int x, y;
        scanf("%d %d", &y, &x);

        LOCS[i].y = y - 1;
        LOCS[i].x = x - 1;
    }

    for (int y = 0; y < R; ++y) {
        ROWSUM[y][0] = TABLE[y][0];
        for (int x = 1; x < C; ++x) {
            ROWSUM[y][x] = ROWSUM[y][x - 1] + TABLE[y][x];
        }
    }

    calSameRow();
    

    // min dist
    for (int uy = 0; uy < R; ++uy) {
        for (int ux = 0; ux < 2; ++ux) {
            for (int vy = uy + 1; vy < R; ++vy) {
                for (int vx = 0; vx < 2; ++vx) {
                    DIST[uy][ux][vy][vx] = DIST[vy][vx][uy][ux] = min(
                        DIST[uy][ux][vy - 1][0] + DIST[vy][0][vy][vx],
                        DIST[uy][ux][vy - 1][1] + DIST[vy][1][vy][vx]);
                }
            }
        }
    }


    long long res = getResult();
    printf("%lld", res);
}