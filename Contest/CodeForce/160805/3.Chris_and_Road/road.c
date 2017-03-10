#include <stdio.h>

int main() {

    int n, w, v, u, i;
    scanf("%d%d%d%d",&n,&w,&v,&u);

    int x[n], y[n];
    int left, right, top, bottom;
    scanf("%d%d", &x[0], &y[0]);
    left = x[0];
    right = x[0];
    top = y[0];
    bottom = y[0];

    for (i=1; i<n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        if (x[i] < left)
            left = x[i];
        if (x[i] > right)
            right = x[i];
        if (y[i] > top)
            top = y[i];
        if (y[i] < bottom)
            bottom = y[i];
    }
    int left_bottom = -1, left_top = -1;
    for (i=0; i<n; i++) {
        if (x[i] == left) {
            if (left_bottom == -1 || y[i] < left_bottom)
                left_bottom = y[i];
            if (left_top == -1 || y[i] > left_top)
                left_top == y[i];
        }
    }

    double time = 0;

    printf("%lf\n",time);
    return 0;
}
