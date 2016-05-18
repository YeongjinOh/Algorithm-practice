#include <stdio.h>

char ch[1000][1001];

int main() {

	// number of row and column
	int row, col;
	scanf("%d%d", &row, &col);

	// get string
	int i, j;
	char none;
	for (i=0; i<row; i++) {
		scanf("%s",&ch[i][0]);
	}

	/* bucket sort */

	int bucket[26][col], cnt[26], idx;
	int ptr[col], r, c;
	for (i=0; i<col; i++)
		ptr[i]=i;

	for (r=0; r<row; r++) {

		// reset cnt of each bucket
		for (i=0; i<26; i++)
			cnt[i]=0;

		// put into bucket
		for (i=0; i<col; i++) {
			c = ptr[i];
			idx = (ch[r][c]-'a');
			bucket[idx][cnt[idx]++]=c;
		}

		// rearrange
		idx = 0;
		for (i=0; i<26; i++)
			for (j=0; j<cnt[i]; j++) 
				ptr[idx++] = bucket[i][j];
	}

	// draw sorted result
	/*
		 for (i=0; i<row; i++) {
		 for (j=0; j<col; j++)
		 printf("%c",ch[i][ptr[j]]);
		 printf("\n");
		 }
		 */

	int min=row, cur;
	for (i=0; i<col-1; i++) {
		cur = min;
		while (cur < row && ch[cur][ptr[i]] == ch[cur][ptr[i+1]]) {cur++;}
		if (cur != row)
			continue;
		
		cur = min-1;
		while (cur>=0 && ch[cur][ptr[i]] == ch[cur][ptr[i+1]]) {cur--;}
		if (cur<min)
			min = cur;
	}
	printf("%d\n",min);
}

