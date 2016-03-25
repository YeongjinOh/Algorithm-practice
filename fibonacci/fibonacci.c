#include <stdio.h>

#define INTEGER_UNIT 1000000
#define BIG_INTEGER_LENGTH 10

struct big_integer {
	int unit_integer[BIG_INTEGER_LENGTH];
	int length;
};

// Return the summation of two big integers
struct big_integer sum_of_big_integer(struct big_integer a, struct big_integer b)
{
	// To do
	return a;
}


// Tail recursive of fibonacci function
struct big_integer fibonacci(int n, struct big_integer a, struct big_integer b)
{
	if (n == 0)
		return a;
	else if (n == 1)
		return b;
	else if (n < 0)
	{
		struct	big_integer zero;
		zero.unit_integer[0]=0;
		zero.length = 1;
		return zero;
	}
	else
		return fibonacci(n-1, b, sum_of_big_integer(a,b));
}

// Print the given big integer number
void print_big_integer (struct big_integer I)
{
	int i;
	for(i=I.length; i>0; i++)
		printf("%d",I.unit_integer[i-1]);
	printf("\n");
}

int main(void)
{
	// Get input n
	int n;
	scanf("%d", &n);

	// Initialize big_integer
	struct big_integer a, b;
	a.length = 1;
	b.length = 1;
	b.unit_integer[0]=1;

	// Print the output of fibonacci(n)
	print_big_integer(fibonacci(n, a, b));

	return 0;
}
