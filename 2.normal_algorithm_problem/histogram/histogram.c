#include <stdio.h>

int min (int a, int b) {
	return a > b? b: a;
}

int max (int a, int b) {
	return a > b? a: b;
}

int max_area(int hist[], int a, int b)
{
	// base case
	if (a == b)
		return hist[a];
	else if (b == a+1)
		return 2*min(hist[a], hist[b]);

	int size = (b-a)/2+1;
	int min_length = 0;

	// remember the left and right position of new histogram
	int left[size], right[size];

	int i, min_hist;
	
	// for the case that hist[a] is minimum
	min_hist=hist[a];
	left[0] = a+1;
	
	//	int min_i=a;
	
	for (i=a+1; i<=b; i++) {

		// if minimum should be reset
		if (min_hist > hist[i]) {
			min_hist = hist[i];
		
			// reset minimum
			left[0] = a;
			right[0] = i-1;
			min_length = 1;

			left[1] = i+1;
		
		// if current value is same with minimum
		} else if (hist[i] == min_hist) {

			// consecutive minimum case
			if (hist[i-1] == min_hist) 
				left[min_length] = i+1;
			else {
				right[min_length++] = i-1;
				left[min_length] = i+1;
			}
		}
	}

	// for the case that hist[b] is not minimum
	if (hist[b] != min_hist)
		right[min_length++] = b;

	int result = (b-a+1)*min_hist;
	for (i=0; i<min_length; i++)
		result = max(result, max_area(hist, left[i], right[i]));
	
	return result;
}

int main(void) {
	int n, i;
	scanf("%d",&n);
	
	int hist[n];
	for (i=0; i<n; i++)
		scanf("%d",&hist[i]);

	printf("%d\n", max_area(hist,0,n-1));

	return 0;
}
