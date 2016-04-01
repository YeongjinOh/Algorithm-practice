#include <stdio.h>
#include <stdbool.h>

int length(char str[])
{
	int i=0;
	while(str[i++] != '\0') {}
	
	return i-1;
}

long long alpha(char str[], int idx, long long a, long long b)
{
	long long mod = 1000000;
	int cur = str[idx]-'0';

	// when last
	if(idx == (length(str)-1)) {
		if (cur == 0)
			return a;
		else
			return (a+b)%mod;
	} else {
		int next = str[idx+1]-'0';
		if( (cur == 1) || ((cur == 2) && (next <= 6)) )
			return alpha(str, idx+1, b, (a+b)%mod);
		else if(cur == 0)
			return alpha(str, idx+1, 0, a);
		else
			return alpha(str, idx+1, 0, (a+b)%mod);
	}
}


int main(void)
{
	char str[5001];

	scanf("%s",str);
	
			


	printf("%lld",alpha(str, 0, 0, 1));


	return 0;
}
