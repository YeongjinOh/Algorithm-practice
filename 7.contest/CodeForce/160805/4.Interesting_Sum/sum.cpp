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

    // build integral d value
    // uni takes d only for unique value
    int d[n+1], uni[n+1];
    d[0] = 0;
    uni[0] = 0;
    for (i=1; i<=n; i++) {
        d[i] = d[i-1]^num[i-1];
    }

    // for each query
    for (i=0; i<m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("res : %d\n",d[l-1]^d[r]);
    }

    return 0;
}
