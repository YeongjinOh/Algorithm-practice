#include <stdio.h>

// count how many times n! is divisible by div
long long count_dividor (long long n, long long div) {
	long long cnt = 0, unit = div;
	while (n >= div) {
		cnt += n/div;
		div *= unit;
	}
	return cnt;
}

int main() {
	// 0 <= m <= n <= 2,000,000,000
	long long n, m;
	scanf("%lld%lld",&n, &m);

	// use the property nCm = n!/(m!*(n-m)!)
	long long two, five;
	two = count_dividor(n,2) - count_dividor(m,2) - count_dividor(n-m,2);
	five = count_dividor(n,5) - count_dividor(m,5) - count_dividor(n-m,5);

	// print minimal value
	printf("%lld\n",two>five?five:two);
}
