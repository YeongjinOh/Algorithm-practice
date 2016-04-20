#include <stdio.h>

int max (int a, int b) {
	return a > b? a: b;
}

int max_area_using_stack(int hist[], int a, int b) {
	int stack[b-a];
	int i, cnt=0;

	stack[cnt++] = a;
	int res = hist[a];


	for (i=a; i<=b; i++) {
		while (hist[stack[cnt-1]] > hist[i]) {

			// pop the last element from the stack
			cnt--;
			res = max (res, (i-1-stack[cnt-1])*hist[stack[cnt]]);
		}
		stack[cnt++] = i;
	}

	return res;
}


int main(void) {
	int n, i;
	scanf("%d",&n);
	
	int hist[n+2];
	hist[0] = 0;
	hist[n+1] = 0;
	for (i=1; i<=n; i++)
		scanf("%d",&hist[i]);

	printf("%d\n", max_area_using_stack(hist, 0, n+1));

	return 0;
}
