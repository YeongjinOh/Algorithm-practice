#include <stdio.h>

int main() {

    // number of elemetns
    int n, i, m;
    scanf("%d",&n);
    int num[n];
    for (i=0; i<n; i++) {
        scanf("%d",&num[i]);
    }
    scanf("%d",&m);

    // build integral XOR value
    // uni takes XOR only for unique value
    int xor[n+1], uni[n+1];
    xor[0] = 0;
    uni[0] = 0;
    for (i=1; i<=n; i++) {
        xor[i] = xor[i-1]^num[i-1];
    }

    // for each query
    for (i=0; i<m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("res : %d\n",xor[l-1]^xor[r]);
    }

    return 0;
}
