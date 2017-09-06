#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
 
int main() {
    int n, a, b, end, count = 1;
    vector<pair<int, int> > v;
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
 
    sort(v.begin(), v.end());

    end = v[0].first;
    for (int i = 1; i < n; i++) {
        if (v[i].second >= end) {
            count++;
            end = v[i].first;
        }
    }
 
    cout << count << endl;
 
    return 0;
}