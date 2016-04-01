#include <stdio.h>

int min(int a, int b) {
	if (a>b)
		return b;
	else
		return a;
}

int main(void)
{
	// Initialize
	int N, i, red_min=0, green_min=0, blue_min=0, red, green, blue, tmp_red, tmp_green;

	// Get the number of houses
	scanf("%d", &N);

	// Get the cost of i-th house for each color
	for (i=0; i<N; i++)
	{
		scanf("%d%d%d", &red, &green, &blue);
		// Keep saving the trace to calculate minimum cost
		tmp_red = red_min;
		red_min = red + min(green_min, blue_min);
		tmp_green = green_min;
		green_min = green + min(tmp_red, blue_min);
		blue_min = blue + min(tmp_red, tmp_green);
	}

	// Print the output
	printf("%d\n", min(red_min, min(green_min, blue_min)) );

	return 0;
}
