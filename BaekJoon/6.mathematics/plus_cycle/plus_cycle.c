#include <stdio.h>

int main(void) 
{
	// 0 <= n <= 99
	int n, tmp, cnt;
	scanf("%d",&n);
	tmp = n;
	cnt = 0;
	do {
		tmp = (tmp%10)*10 + ((tmp/10) + (tmp%10))%10;
		cnt++;
	} while(tmp != n);

	printf("%d\n",cnt);
	return 0;
}
