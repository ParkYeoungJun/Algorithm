#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int map[20][20];

void printMap(int N){
    for(int i = 0;i<N;i++){
          for(int j = 0;j<N;j++){
              printf("%d ",map[i][j]);
          }
        printf("\n");
        }
}

int main(){
    int T;
    scanf("%d",&T);

    for(int t = 1;t<=T;t++){
        int N,X;
        scanf("%d %d",&N,&X);

        for(int i = 0;i<N;i++){
          for(int j = 0;j<N;j++){
              scanf("%d",&map[i][j]);
          }
        }
    //printMap(N);
        
        int cur = 0;
        int st = 0;
        int res = 0;
        for(int j = 0;j<N;j++){
            cur = map[0][j];
            st = 1;
            bool check = false;
            bool isTrue = true;
            for(int i = 1;i<N;i++){
                if(map[i][j] == cur){
                    st++;
                    if(check && X == st){
                        check = false;
                        st = 0;
                    }
                }else if(fabs(map[i][j]-cur) == 1){
                    if(check) {
                        isTrue = false; 
                        //cout<<"dd1"<<endl;
                        break;
                    }
                    else if(map[i][j] > cur && X > st) {isTrue = false;}//cout<<"dd2"<<map[i][j]<<" "<<cur<<" "<<" "<<st<<i<<j<<endl; break;}
                    else if(map[i][j] < cur){
                        check = true;                    
                    }
                    cur = map[i][j];
                    st = 1;
                }else{
                    isTrue = false;
                    break;
                }
            }
            if(!check && isTrue ) {res++;}//cout<<j<<endl;}
        }

        for(int i = 0;i<N;i++){
            
            cur = map[i][0];
            st = 1;
            bool check = false;
            bool isTrue = true;

            for(int j = 1;j<N;j++){
                
                if(map[i][j] == cur){
                    st++;
                    if(check && X == st){
                        check = false;
                        st = 0;
                    }
                }else if(fabs(map[i][j]-cur) == 1){
                    if(check) {
                        isTrue = false;
                        //cout<<"dd3"<<endl; 
                        break;
                    }
                    else if(map[i][j] > cur && X > st) {isTrue = false;}//cout<<"dd4"<<endl; break;}
                    else if(map[i][j] < cur){
                        check = true;                    
                    }
                    cur = map[i][j];
                    st = 1;
                }else{
                    isTrue = false;
                    break;
                }
            }
            if(!check && isTrue) {res++;}//cout<<"d"<<i<<endl;}
        }
        printf("#%d %d\n",t,res);
    }
}