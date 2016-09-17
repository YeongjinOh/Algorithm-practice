#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int n, c;
    scanf("%d%d",&n,&c);
    int res = 0;
    int prev = 0, cur;
    while(n--) {
        scanf("%d",&cur);
        if (cur-prev > c)
            res = 1;
        else
            res++;
        prev = cur;
    }
    printf("%d\n",res);
    return 0;
}
