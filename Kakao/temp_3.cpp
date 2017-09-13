#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    if(a[0] < b[0])
        return true;
    
    return false;
}

vector<int> solution(vector<vector<int> > v) {
    
    vector<int> ans;
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0 ; i < 3 ; ++i)
    {
        for(int j = 0 ; j < 2 ; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }

    if(v[1][0] == v[0][0])
    {
        ans.push_back(v[2][0]);
    
        if(v[0][1] == v[2][1])
            ans.push_back(v[1][1]);
        else
            ans.push_back(v[0][1]);
    }
    else
    {
        ans.push_back(v[0][0]);
        
        if(v[0][1] == v[1][1])
            ans.push_back(v[2][1]);
        else
            ans.push_back(v[1][1]);
    }
    
    return ans;
}