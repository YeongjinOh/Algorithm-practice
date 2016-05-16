#include <stdio.h>

int main() {

	// out goal is to build Xcm-stick using small piece of 64cm stick
	int X;
	scanf("%d", &X);

	// This problem is equivalent to the problem to count 1 in binary number of X
  int	cnt = 0;
	while (X) {
		cnt += X%2;
		X/=2;
	}

	printf("%d\n",cnt);

	return 0;
}

