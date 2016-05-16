#include <stdio.h>

int rev(int X) {
	int res=0;
	while (X > 0) {
		res = res*10 + (X%10);
		X = X/10;
	}
	return res;
}

int main() {
	
	// Out goal is to calculate rev(rev(X)+rev(Y))
	int X, Y;
	scanf("%d%d", &X, &Y);
	printf("%d",rev(rev(X)+rev(Y)));
	return 0;
}
