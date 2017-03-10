#include <stdio.h>

int main() {

	// get input n
	int n, i;
	scanf("%d", &n);

	long long d[2][10];
	for (i=1; i<10; i++)
		d[0][i]=1;
	d[0][0]=0;

	int j, cur=0, prev;
	for (i=1; i<n; i++) {
	
		prev=cur;
		cur=1-cur;
		
		for (j=0; j<10; j++) {	
		
			d[cur][j] = 0;
			if(j!=0)
				d[cur][j] += d[prev][j-1];
			if(j!=9)
				d[cur][j] += d[prev][j+1];
			d[cur][j]%=1000000000;
		}
	}

	long long sum=0;
	for (i=0; i<10; i++)
		sum += d[cur][i];

	printf("%lld\n", sum%1000000000);

	return 0;
}
