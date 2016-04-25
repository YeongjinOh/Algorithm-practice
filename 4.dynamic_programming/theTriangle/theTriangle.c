#include <stdio.h>

int max (int a, int b) { return a>b?a:b; }

int main(void) {

	// the height of triangle
	int h, i, j;
	scanf("%d", &h);

	// the number of numbers in triangle
	int n = h*(h+1)/2;

	// get the numbers
	int tri[n];
	for (i=0; i<n; i++)
		scanf("%d", &tri[i]);

	// for each height
	int start;
	for (i=h-1; i>=1; i--) {
		start = i*(i-1)/2;
		for (j=start; j<start+i; j++)
			tri[j] += max(tri[j+i], tri[j+i+1]);
	}

	printf("%d",tri[0]);
}
