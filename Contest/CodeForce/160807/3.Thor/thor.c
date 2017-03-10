#include <stdio.h>

int main() {
    int n, q, i, j;
    scanf("%d%d", &n, &q);
    int num[n+1], queue[q], hd=0, cur=0, last[n+1];
    int type, x, cnt = 0, tmp, max;

    for (i=0; i<=n; i++) {
        num[i] = 0;
        last[i] = -1;
    }

    for (i=0; i<q; i++) {
        scanf("%d%d", &type, &x);
        if (type == 1) {
            num[x]++;
            cnt++;
            queue[cur++] = x;
        } else if (type == 2) {
            cnt -= num[x];
            num[x] = 0;
            last[x] = cur-1;
        } else {
            for (j=hd; j<x; j++) {
                tmp = queue[j];
                if (tmp != -1 && last[tmp] < j) {
                    num[tmp]--;
                    cnt--;
                }
            }
            if (hd < x)
                hd = x;
        }
        printf("%d\n", cnt);
/*
        printf("cur:%d hd:%d\n",cur, hd);
        for (i=0; i<n; i++)
            printf("%d ",num[i+1]);
        printf("\n");
  */
        }



    return 0;
}
