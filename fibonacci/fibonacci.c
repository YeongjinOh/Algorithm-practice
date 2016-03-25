#include <stdio.h>

#define INTEGER_UNIT 10000
#define BIG_INTEGER_LENGTH 10

struct big_integer {
	int integer_array[BIG_INTEGER_LENGTH];
	int length;
};

// Return the summation of two big integers
struct big_integer sum_of_big_integer(struct big_integer a, struct big_integer b)
{
	// Suppose that a<b
	
	// initialization
	int i, l = a.length;
	int sum, carry = 0;
	
	for(i=0; i<l; i++)
	{
		// Get sum and carry
		sum = a.integer_array[i] + b.integer_array[i] + carry;
		carry = sum / INTEGER_UNIT;
		sum = sum % INTEGER_UNIT;
		
		// Change a since we will return it as output
		a.integer_array[i] = sum;
	}
	int new_digit = b.integer_array[l] + carry;
	if (new_digit > 0)
	{
		a.integer_array[l] = new_digit;
		a.length = l+1;
	}
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
		zero.integer_array[0]=0;
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
	for(i=I.length; i>0; i--)
		printf("%d",I.integer_array[i-1]);
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
	int i;
	for (i=0; i<BIG_INTEGER_LENGTH; i++)
	{
		a.integer_array[i] = 0;
		b.integer_array[i] = 0;
	}
	b.integer_array[0]=1;

	// Print the output of fibonacci(n)
	print_big_integer(fibonacci(n, a, b));

	return 0;
}
