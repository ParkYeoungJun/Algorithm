#include<iostream>
#include<cstdio>

using namespace std;

const int LM = (int)1e6;

int arr[LM];
int tree[LM];

void build(int now, int s, int e) {
    if(s == e) {
        tree[now] = arr[s];
        return ;
    }

    int lch = now * 2, rch = lch + 1, m = (s + e)/2;
    build(lch, s, m);
    build(rch, m+1, e);
    tree[now] = tree[lch] + tree[rch];
}

void update(int now, int s, int e, int idx, int val) {
    if(s == e) {
        tree[now] = val;
        return
    }
    int lch = now * 2, rch = lch + 1, m = (s + e)/2;
    if(idx <= m) update(lch, s, m);
    else update(rch, m+1,e);

    tree[now] = tree[lch] + tree[rch];
}

int query(int now, int s, int e, int fs, int fe) {
    if(s > fe || e < fs) return 0;
    if(fs <= s && e <= fe) return tree[now];

    int lch = now * 2, rch = lch + 1, m = (s + e)/2;
    int l = query(lch, s, m, fs, fe);
    int r = query(rch, m+1, e, fs, fe);

    int rtn = l + r;
    return rtn;
}

int main() {
    return 0;
}