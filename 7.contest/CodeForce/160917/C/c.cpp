#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int n;
    scanf("%d",&n);
    long long cur=2;
    for (long long i=1; i<=n; i++) {
        // at each level i
        long long goal = (i+1)*(i+1);
        long long res = (long long)(goal*i - cur);
        if (res > 10000000000000000 || res < 2) {
            printf("%lld break\n",res);
            return 0;
        }
        printf("%lld\n",res);
        cur = i;
    }
    return 0;
}
