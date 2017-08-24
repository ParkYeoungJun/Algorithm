#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
 
using namespace std;
 
int main(void) {

  int num, in;

  long long int c = 0;

  map<int, long long int> mapArr;
  map<int, long long int>::iterator lower_bound;
  map<int, long long int>::iterator upper_bound;
 
  mapArr.insert(pair<int, long long int>(0, -1));
  mapArr.insert(pair<int, long long int>(300001, -1));

  scanf("%d", &num);
 
  for (int i = 0; i < num; i++) {

    scanf("%d", &in); 

    long long int dep = 0;

    lower_bound = (--mapArr.lower_bound(in));
    upper_bound = (mapArr.upper_bound(in));

    dep = max(lower_bound->second, upper_bound->second) + 1;
     
    mapArr.insert(pair<int, long long int>(in, dep));

    c += dep;
    
    printf("%lld\n", c);
  }
 
  return 0;
}