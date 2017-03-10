#include <stdio.h>

int main() {
    int n, k, i;
    scanf("%d%d",&n, &k);
    // beauty value and index of capital
    int b[n], c[k], bsum = 0;;
    for (i=0; i<n; i++) {
        scanf("%d",&b[i]);
        bsum += b[i];
    }
    int csum = 0;
    for (i=0; i<k; i++) {
        scanf("%d", &c[i]);
        csum += b[c[i]-1];
    }

    int total = b[0]*b[n-1];
    for (i=0; i<n-1; i++) {
        total += b[i]*b[i+1];
    }

    // add all capitals
    int idx;
    if (c[0] == 1) {
        idx = c[0]-1;
        total += (bsum-b[idx+n-1]-b[idx]-b[idx+1])*b[idx];
    } else {
        idx = c[0]-1;
        total += (bsum-b[idx-1]-b[idx]-b[idx+1])*b[idx];
    }
    for (i=1; i<k; i++) {
        idx = c[i]-1;
        total += (bsum-b[idx-1]-b[idx]-b[idx+1])*b[idx];
    }

    // subtract overlapping values
    int next_idx;
    for (i=0; i<k-1; i++) {
        int cur_csum = csum;
        idx = c[i]-1; // current index
        next_idx = c[i+1]-1;
        cur_csum -= b[idx];
        if (idx + 1 == next_idx)
            cur_csum -= b[next_idx];
        total -= cur_csum*b[idx];
        csum -= b[idx];
    }
    printf("%d\n", total);


}
