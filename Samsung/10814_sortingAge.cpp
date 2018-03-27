#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct client {
    int age;
    char name[105];
    int num;
} client;

vector<client> array;

bool compare(client a, client b) {
    if(a.age < b.age)
        return true;
    else if(a.age == b.age)
        return a.num < b.num;
    else
        return false;
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; ++i)
    {
        client tmp;

        scanf("%d %s", &tmp.age, tmp.name);
        
        tmp.num = i;

        array.push_back(tmp);
    }
    
    sort(array.begin(), array.end(), compare);

    for(int i = 0 ; i < array.size() ; ++i)
        printf("%d %s\n", array[i].age, array[i].name);
}