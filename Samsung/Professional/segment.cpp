#include<iostream>
#include<cstdio>

using namespace std;

int N, M, K;

const int LM = (int)1e6;
const int MOD = 1000000007;

long long int arr[LM + 5];
long long int tree[LM * 3];

void build(int now, int s, int e){
    if(s == e) {
        tree[now] = arr[s];
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    build(lch, s, m);
    build(rch, m + 1, e);

    tree[now] = (tree[lch] * tree[rch]) % MOD;
} 

void update(int now, int s, int e, int idx, int val) {
    if(s == e) {
        tree[now] = val;
        return ;
    }

    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    if(idx <= m) update(lch, s, m , idx, val);
    else update(rch, m + 1, e, idx, val);

    tree[now] = (tree[lch] * tree[rch]) % MOD;
}

int query(int now, int s, int e, int fs, int fe) {
    if(s > fe || e < fs) return 1;
    if(fs <= s && e <= fe) return tree[now];

    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    int l = query(lch, s, m, fs, fe);
    int r = query(rch, m + 1, e, fs, fe);

    return (l * r) % MOD;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for(int i = 1 ; i <= N ; ++i) {
        scanf("%d", &arr[i]);
    }

    build(1, 1, N);



    int a, b, c;
    for(int i = 0 ; i < M + K ; ++i){
        scanf("%d %d %d", &a, &b, &c);

        if(a == 1){
            arr[b] = c;
            update(1, 1, N, b, c);
        }
        else if(a == 2){
            int rtn = query(1, 1, N, b, c);

            printf("%d\n", rtn);
        }
    }

    return 0;
}