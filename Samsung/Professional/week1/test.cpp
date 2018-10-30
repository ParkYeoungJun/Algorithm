#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
      for(int i = 0 ; i < 10 ; ++i){
         for(int j = 0 ; j < 10 ; ++j){
            if(i != j) {
                for(int k = 0 ; k < 10 ; ++k){
                    if(i != k && j != k) {
                        for(int h = 0 ; h < 10 ; ++h) { 
                            if(i != h && j != h && k != h) {
                                cout << i << " " << j << " " << k << " " << h << endl;
                            }
                        }
                        
                    }
                }
            }
         }
    }

    return 0;
}