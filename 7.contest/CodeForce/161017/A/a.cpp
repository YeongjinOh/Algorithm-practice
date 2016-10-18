#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


int main () {
    int k, r;
    scanf("%d%d",&k, &r);
    int cnt = 1;
    while( (cnt*k) % 10 != 0 && (cnt*k) % 10 != r) {
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
