#include <stdio.h>
#include <stdbool.h>
long long diff (long long a, long long b) {
    if (a>b)
        return (a-b);
    else
        return (b-a);
}

int main() {
    int n, s, e, i, j;
    scanf("%d%d%d",&n,&s,&e);
    long long x[n], a[n], b[n], c[n], d[n];
    bool flag[n];
    for (i=0; i<n; i++) { scanf("%lld",&x[i]);}
    for (i=0; i<n; i++) { scanf("%lld",&a[i]);}
    for (i=0; i<n; i++) { scanf("%lld",&b[i]);}
    for (i=0; i<n; i++) { scanf("%lld",&c[i]);}
    for (i=0; i<n; i++) { scanf("%lld",&d[i]);}
    for (i=0; i<n; i++) { flag[i]=true; }
    flag[s-1] = false;
    flag[e-1] = false;
    long long amount = 0, min_val=-1, cur_val;
    int cur = s, next;
    for (i=0; i<n-2; i++) {
        min_val = -1;
        for (j=0; j<n; j++) {
            if(flag[j]) {
                if (j < cur) {
                    cur_val = diff(x[cur],x[j]) + c[cur] + b[j];
                } else {
                    cur_val = diff(x[cur],x[j]) + d[cur] + a[j];
                }
                if (min_val == -1 || min_val > cur_val) {
                    min_val = cur_val;
                    next = j;
                }
            }
        }
        amount += min_val;
        cur = next;
        flag[cur] = false;

        printf("%d\n", cur);
    }
    if (e < cur)
        amount += diff(x[cur],x[e]) + c[cur] + b[e];
    else
        amount += diff(x[cur],x[e]) + d[cur] + a[e];

    printf("%lld\n",amount);


    return 0;
}
