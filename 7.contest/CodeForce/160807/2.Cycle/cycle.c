#include <stdio.h>

int main() {
    int i, n, v;
    scanf("%d", &n);
    int flag = 0;
    for (i=0; i<n; i++) {
        scanf("%d",&v);
        flag += (v-1);
        flag = flag%2;
        printf("%d\n", 2-flag);
    }

    return 0;
}
