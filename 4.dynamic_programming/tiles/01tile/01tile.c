#include <stdio.h>
#define MOD 15746
int fib(int a, int b, int n) {
	if (n==1)
		return a;
	else if (n==2)
		return b;
	else
		return fib(b, (a+b)%MOD, n-1);
}

int main() {

	// get input
	int n;
	scanf("%d", &n);	
	printf("%d", fib(1,2,n));
}

