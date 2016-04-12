#include <stdio.h>

int main() {
	int n, tmp;
	scanf("%d",&n);
	int sum = 1-n;
	while(n--)
	{
		scanf("%d",&tmp);
		sum += tmp;
	}
	printf("%d",sum);
	return 0;
}
