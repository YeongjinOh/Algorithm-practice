#include <stdio.h>

typedef int ll;
ll n, k, l, r, a, b;

int main() {
    scanf("%d", &n);
    printf("%d",n%2==0?1:7);
    for (ll i=1; i<n/2; ++i)
        printf("1");
    printf("\n");

    return 0;
}
