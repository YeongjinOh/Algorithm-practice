#include <stdio.h>
 
int fib(int a, int b, int n) {
    if (n==1)
        return a;
    else if (n==2)
        return b;
    else
        return fib(b, (a+b)%10007, n-1);
}
 
int main(void) {
 
    // number of columns
    int n;
    scanf("%d", &n);
 
    // This problem is equivalent to the fibonacci problem
    printf("%d\n", fib(1,2,n));
 
    return 0;
}
