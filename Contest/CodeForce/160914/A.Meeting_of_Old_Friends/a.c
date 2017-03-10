#include <stdio.h>

int main() {
    long long l1, r1, l2, r2, k;
    scanf("%lld%lld%lld%lld%lld",&l1,&r1,&l2,&r2,&k);
    long long res;
    if (l1 > r2 || l2 > r1)
        res = 0;
    else {
        long long left = l1>l2?l1:l2;
        long long right = r1>r2?r2:r1;
        if (left <= k && k <= right)
            res = right-left;
        else
            res = right-left+1;
    }
    printf("%lld\n",res);
}
