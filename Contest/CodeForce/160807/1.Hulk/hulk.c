#include <stdio.h>

int main() {
    int n, i;
    scanf("%d",&n);
    printf("I hate ");
    for (i=1; i<n; i++) {
        if (i%2 == 0)
            printf("that I hate ");
        else
            printf("that I love ");
    }
    printf("it\n");
}
