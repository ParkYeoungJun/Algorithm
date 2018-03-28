#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<char> arr;

bool compare(char a, char b)
{
    return a > b;
}

int main()
{
    char c;

    while(scanf("%c", &c) != EOF)
    {
        arr.push_back(c);
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0 ; i < arr.size() ; ++i)
        printf("%c", arr[i]);
}