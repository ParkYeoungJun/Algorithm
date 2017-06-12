/*
 * Bargaint.cpp
 *
 *  Created on: 2015. 10. 15.
 *      Author: Park
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	 std::ios::sync_with_stdio(false);


	 // insert

	 int pro_size;

	 cin >> pro_size;

	 int temp = 0;

	 if(pro_size == 0)
	 {
		 cin >> pro_size;

		 if(pro_size == 0)
			 cout << 0;
		 else
		 {
			 int* product;

			 product = new int [3];

			 for(int k = 0 ; k < pro_size ; ++k)
			 {
		 	 		 for(int i = 0 ; i < 3 ; ++i)
		 	 		 {
		 	 			 cin >> product[i];
		 	 		 }

		 	 		 for(int i = 0 ; i < product[1] ; ++i)
		 	 			 temp += product[2];
			 }

			 cout << temp;
		 }
	 }
	 else
	 {
		 int** pro_group;

		 pro_group = new int* [pro_size];

		 int tmp = 0;

		 int u ;

		 for(int i = 0 ; i < pro_size ; ++i)
		 {
			 cin >> u;

			 pro_group[i] = new int[u*2+2];

			 pro_group[i][0] = u;

			 for(int j = 1 ; j < u*2+2 ; ++j)
				 cin >> pro_group[i][j];
		 }

		 int buy_size;

		 cin >> buy_size;

		 int** buy;

		 buy = new int* [5];

		 for(int i = 0 ; i < 5 ; ++i)
			 buy[i] = new int[3];

		 for(int i = 0 ; i < buy_size ; ++i)
			 for(int j = 0 ; j < 3 ; ++j)
				 cin >> buy[i][j];

		 // item matching

		 for(int i = 0 ; i < pro_size ; ++i)
		 {
			 for(int j = 1 ; j < pro_group[i][0]*2 ; j+=2)
			 {
				 for(int k = 0 ; k < 5 ; ++k)
				 {
					 if(pro_group[i][j] == buy[k][0])
					 {
						 pro_group[i][j] = k+1;
					 }
				 }
			 }
		 }

		 // store product's size

		 int** store;

		 store = new int* [pro_size];

		 for(int i = 0 ; i < pro_size ; ++i)
			 store[i] = new int [5];

		 for(int i = 0 ; i < pro_size ; ++i)
			 for(int j = 1; j < pro_group[i][0]*2 ; j += 2){
				 store[i][pro_group[i][j]-1] = pro_group[i][j+1];
		 }

		 int di[6][6][6][6][6];

		 // 필요한 만큼 di 배정

		 for(int a = 0 ; a <= buy[0][1] ; ++a)
			 for(int b = 0 ; b <= buy[1][1] ; ++b)
				 for(int c = 0 ; c <= buy[2][1] ; ++c)
					 for(int d = 0 ; d <= buy[3][1] ; ++d)
						 for(int e = 0 ; e <= buy[4][1] ; ++e)
						 {
							 di[a][b][c][d][e] = buy[0][2]*a + buy[1][2]*b +
									 buy[2][2]*c + buy[3][2]*d + buy[4][2]*e;
						 }

		 // Logic

		 for(int a = 0 ; a <= buy[0][1] ; ++a)
			 for(int b = 0 ; b <= buy[1][1] ; ++b)
				 for(int c = 0 ; c <= buy[2][1] ; ++c)
					 for(int d = 0 ; d <= buy[3][1] ; ++d)
						 for(int e = 0 ; e <= buy[4][1] ; ++e)
						 {

							 for(int i = 0 ; i < pro_size ; ++i)
							 {
								 if(a >= store[i][0] && b >= store[i][1] && c >= store[i][2]
									&&	d >= store[i][3] && e >= store[i][4])
								 {

									 di[a][b][c][d][e] = min(di[a][b][c][d][e] , pro_group[i][pro_group[i][0]*2+1]
         																       + di[a-store[i][0]][b-store[i][1]][c-store[i][2]][d-store[i][3]][e-store[i][4]]);
								 }
							 }
						 }

		 cout << di[buy[0][1]][buy[1][1]][buy[2][1]][buy[3][1]][buy[4][1]];
	 }
}
