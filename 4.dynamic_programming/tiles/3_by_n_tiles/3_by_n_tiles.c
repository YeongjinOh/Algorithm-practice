#include <stdio.h>
 
int main() {
     
    // number of columns
    int n;
    scanf("%d", &n);
    if (n%2 == 1)
        printf("0");
    else {
        n/=2;
        int res;
        if(n==1)
            res = 3;
        else if (n==2)
            res = 11;
        else {
            int d[n];
            d[0] = 3;
            d[1] = 11;
            int i;
            for (i=2; i<n; i++)
                d[i] = 4*d[i-1]-d[i-2];
            res = d[n-1];
        }
        printf("%d",res);
    }
    return 0;
}
