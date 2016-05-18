#include <stdio.h>

char ch[1000][1001];

int main() {

	// number of row and column
	int r, c;
	scanf("%d%d", &r, &c);

	// get string
	int i, j;
	char none;
	for (i=0; i<r; i++) {
		scanf("%s",&ch[i][0]);
	}

	int min=10000, cur;
	for (i=0; i<c-1; i++) {
		for (j=i+1; j<c; j++) {
			cur = r-1;
			while (cur>=0 && ch[cur][i] == ch[cur][j]) {cur--;}
			if (cur<min)
				min = cur;
		}
	}
	printf("%d\n",min);
}

