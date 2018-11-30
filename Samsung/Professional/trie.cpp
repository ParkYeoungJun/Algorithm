#include<cstdio>
#include<iostream>

using namespace std;

typedef struct trie {
    bool finish;
    struct trie* next[10];

    trie(){
        finish = false;
        for(int i = 0 ; i < 10 ; ++i)
            next[i] = NULL;
    }

    ~trie(){
        for(int i = 0 ; i < 10 ; ++i){
            if(next[i]) delete next[i];
        }
    }

    void insert(const char * key) {
        if(*key == '\0') 
            finish = true;
        else {
            int cur = *key - '0';
            if(next[cur] == NULL)
                next[cur] = new trie();
            next[cur]->insert(key + 1);
        }
    }

    bool find(const char * key) {
        if(*key == '\0') return false;
        if(finish) return true;

        int cur = *key - '0';
        next[cur]->find(key+1);
    }
    

}_TRIE;

const int LM = 10005;

char arr[LM][15];

int main()
{
    int t, n;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i = 0 ; i < n ; ++i)
            scanf("%s", &arr[i]);

        _TRIE* root = new _TRIE();

        for(int i = 0 ; i < n ; ++i)
            root->insert(arr[i]);

        bool f = false;
        for(int i = 0 ; i < n ; ++i)
            if(root->find(arr[i])) {
                f = true;
            }
        
        printf("%s\n", f ? "NO" : "YES");
    }


    return 0;
}