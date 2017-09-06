#include<cstdio>
 
int main(){
    int tc;
    scanf("%d", &tc);
 
    while(tc--){
        int len, n, loc,
            min=0, max=0;
        scanf("%d %d", &len, &n);
        while(n--){
            scanf("%d", &loc);
            int cur_min, cur_max;
            if(loc > len-loc)
            {
                cur_min = len-loc;
                cur_max = loc;
            }
            else{
                cur_min = loc;
                cur_max = len-loc;
            }
 
            if(cur_min > min)
                min = cur_min;
            if(cur_max > max)
                max = cur_max;
        }
        printf("%d %d\n", min, max);
    }
 
    return 0;
}