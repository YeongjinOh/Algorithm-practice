#include <stdio.h>

// return reverse number with change from a into b
int change(int num, int a, int b) {
	// find maximal denominator
	int m, r, deno = 1;
	while (num/deno/10) {
		deno *= 10;
	}
	while (deno >0) {
		// num = m*deno+r;
		m = num/deno;
		r = num%deno;
		if (m%10 == a)
			m += (b-a);
		num = m*deno+r;
		deno /= 10;
	}
	return num;
}
int main() {
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	printf("%d %d\n", change(num1,6,5)+change(num2,6,5), change(num1,5,6)+change(num2,5,6));
}
