#include "prime_number.h"

int main(void)
{
	// Initialization with user input
	// N can be any integer within int scope.
	int N;
	scanf("%d",&N);

	// Gererate prime numbers less than or equal to N
	if (N >= 2) {
		prime_number prime;
		generate_prime(N, &prime);
		print_prime(&prime);
	} else {
		printf("Input should be larger than 1\n");
	}


	return 0;
}
