#include <stdio.h>

long long padovan_tail_rec (long long a, long long b, long long c, int k) {
	if (k == 3)
		return c;
	else
		return padovan_tail_rec(b, c, a+b, k-1);
}

long long padovan (int k) {
	if (k==1)
		return 1;
	if (k==2)
		return 1;
	else
		return padovan_tail_rec (1,1,1,k);
}

int main() {
	// get initial input n, 1<=n<=100	
	int n, i, k;
	scanf("%d",&n);
	while(n--) {
		scanf("%d", &k);
		printf("%lld\n", padovan(k));
	}

	return 0;
}
