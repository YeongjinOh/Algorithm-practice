#include <stdio.h>
#define MOD 10007

int main() {
	
	// number of rows
	int n;
	scanf("%d", &n);

	// initialize
	int tmp, one=1, two=0;
	while(--n) {
		tmp = two;
		two = (2*one)%MOD;
		one = (one+tmp)%MOD;
	}

	printf("%d",(one+two)%MOD);

	return 0;
}
