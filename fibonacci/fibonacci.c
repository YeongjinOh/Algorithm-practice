#include <stdio.h>

// Tail recursive of fibonacci function
int fibonacci(int n, int a, int b)
{
	if (n == 0)
		return a;
	else if (n == 1)
		return b;
	else if (n < 0)
		return 0;
	else
		return fibonacci(n-1, b, a+b);
}

int main(void)
{
	// Get input n
	int n;
	scanf("%d", &n);

	// Print the output of fibonacci(n)
	printf("%d\n", fibonacci(n, 1, 1));

	return 0;
}
