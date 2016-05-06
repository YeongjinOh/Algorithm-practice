#include <stdio.h>
#define MOD 1000000000

int main() {

	// the number of digits
	int n;
	scanf("%d",&n);

	// each array means this number meets none of zero and nine, only zero, only nine, or both of them.
	int none[2][10], zero[2][10], nine[2][10], both[2][10];
	
	// initailize
	int i, j;
	for (j=0; j<2; j++) {
		for (i=0; i<10; i++) {
			if (i==0 || i==9)
				none[j][i] = 0;
			else
				none[j][i] = 1;
			zero[j][i] = 0;
			nine[j][i] = 0;
			both[j][i] = 0;
		}
	}
	nine[0][9] = 1;
	
	// calculate the result
	int prev, cur=0;
	for (i=1; i<n; i++) {
		prev = cur;
		cur = 1-cur;
		
		// case 0:
		zero[cur][0] = (zero[prev][1] + none[prev][1])%MOD;
		both[cur][0] = (both[prev][1] + nine[prev][1])%MOD;
		// case 9:
		nine[cur][9] = (nine[prev][8] + none[prev][8])%MOD;
		both[cur][9] = (both[prev][8] + zero[prev][8])%MOD;
		// default:
		for (j=1; j<9; j++) {
			none[cur][j] = (none[prev][j-1] + none[prev][j+1])%MOD;
			zero[cur][j] = (zero[prev][j-1] + zero[prev][j+1])%MOD;
			nine[cur][j] = (nine[prev][j-1] + nine[prev][j+1])%MOD;
			both[cur][j] = (both[prev][j-1] + both[prev][j+1])%MOD;
		}
	}

	int sum=0;
	for (i=0; i<10; i++)
		sum = (sum + both[cur][i])%MOD;
	printf("%d\n", sum);

	return 0;
}
