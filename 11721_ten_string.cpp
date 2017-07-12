#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    string str;
    int cnt = 0;

    getline(cin, str);

    for(int i = 0 ; i < str.size() ; ++i)
    {
        if(cnt == 10)
        {
            printf("\n");
            cnt = 0;
        }

        printf("%c", str.at(i));

        cnt++;
    }
}   
