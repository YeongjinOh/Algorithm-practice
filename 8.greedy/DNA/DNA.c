#include <stdio.h>

int main() {

	// num of rows, columns
	int n,m;
	scanf("%d%d", &n, &m);
	
	// initialize count array
	int cnt[4][m], i, j;
	for (i=0; i<4; i++) {
		for (j=0; j<m; j++) {
			cnt[i][j]=0;
		}
	}
	
	char buf[m+1];
	for (j=0; j<n; j++) {
		// get DNA
		scanf("%s",buf);
		
		// count the number of DNA at each position
		for (i=0; i<m; i++) {
			switch (buf[i]) {
				case 'A':	cnt[0][i]++;	break;
				case 'C':	cnt[1][i]++;	break;
				case 'G':	cnt[2][i]++;	break;
				case 'T':	cnt[3][i]++;	break;
			}
		}
	}

	// find the most frequent DNA at each position
	int res_idx[m], max;
	for (i=0; i<m; i++) {
		max=0;

		for (j=0; j<4; j++) {
			if (max < cnt[j][i]) {
				max = cnt[j][i];
				res_idx[i]=j;
			}
		}
	}
	
	// print result
	char pt;
	int res=0;
	for (i=0; i<m; i++) {
		switch(res_idx[i]) {
			case 0 : pt='A'; break;
			case 1 : pt='C'; break;
			case 2 : pt='G'; break;
			case 3 : pt='T'; break;
		}
		printf("%c",pt);
		res += (n-cnt[res_idx[i]][i]);
	}
	printf("\n%d\n", res);

	return 0;
}
