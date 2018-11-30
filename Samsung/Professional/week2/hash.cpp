#include<iostream>
#include<cstdio>

using namespace std;

const int SIZE = 1 << 25;
const int MOD = SIZE-1;

const int KNUTH = 2654435761;

int table[SIZE];

int hashing(int key) {
    return (n * KNUTH) & MOD;
}

int dj2b(char * key) {
    int h = 5381;
    for(int i = 0 ; key[i] ; ++i) {
        h = ((h << 5) + h + key[i]) % MOD;  
    }
    return h;
}

int main()
{
    return 0;
}