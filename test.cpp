#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
int ptr[15][15];
int dxp[15][15];
int dxp2[15][15];
double gdx[15][15];
	

int main(void) {

	double g[3][3] = {{0.075, 0.124, 0.075}, {0.124, 0.204, 0.124}, {0.075, 0.124, 0.075}};
	int dx[3] = {-1,0,1};

	for(int i = 0 ; i < 12 ; ++i)
		for(int j = 0 ; j < 12 ; ++j)
			cin >> ptr[i][j];

	for(int i = 0 ; i < 12 ; ++i)
		for(int j = 1 ; j < 11 ; ++j) {
				dxp[i][j] = ptr[i][j - 1]*(-1) + ptr[i][j+1];
		}

	
	for(int i = 1 ; i < 12 ; ++i) {
        for(int j = 1 ; j < 12 ; ++j) {

            double v = 0;

            for(int mx = 0 ; mx < 3 ; ++mx)
                for(int my = 0 ; my < 3 ; ++my)
                    v += g[mx][my] * dxp[i + mx - 1][j + my -1];

			gdx[i][j] = v;
        }
    }

	for(int i = 0 ; i < 12 ; ++i){
		for(int j = 0 ; j < 12 ; ++j)
			cout << dxp[i][j] << " ";
		cout << endl;
	}

}