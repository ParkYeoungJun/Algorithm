#include <iostream>
#include <algorithm>
using namespace std;
int a[4] = {1,2,3,4};
int b[4] ={};
int check[5]={};
int myC = 0;
void dfs(int depth){
    // cout << &myC << endl;
    // for(int i = 0 ; i < 4 ; ++i)
    //     cout << b[i] << " ";
    // cout << endl;

    if(depth == 4){
        myC++;
        cout<<myC<<":";
        for(int i = 0;i<4;i++){
            cout<<b[i];
        }
        cout<<endl;
    }else{
        for(int i = 0;i<4;i++){
            if(!check[a[i]]){
                b[depth] = a[i];
                check[a[i]] = 1;
                dfs(depth+1);
                check[a[i]] = 0;
            }
        }
    }
}
int main(){
   dfs(0);
}