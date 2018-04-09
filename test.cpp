#include<iostream>
#include<cstdio>

using namespace std;

typedef struct abc{
    int i;
}b;

b val;

int main()
{
    val.i = 123;
    cout << val.i;
}