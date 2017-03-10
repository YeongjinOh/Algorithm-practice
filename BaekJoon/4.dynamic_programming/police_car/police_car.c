#include <stdio.h>

// d[i][j] means, the optimal solution when the last case
// of car_1 = i, car_2 = j. Since i!=j, diagonal elements never be used.
// b[i][j] means, where this optimal come from.
int d[1001][1001], b[1001][1001];
int x[1000], y[1000];

// distance between two points
int distance (int x1, int y1, int x2, int y2) {
	int dist;
	if (x1 > x2)     dist = x1 - x2;
	else             dist = x2 - x1;
	if (y1 > y2)     dist += y1 - y2;
	else             dist += y2 - y1;
	return dist;
}

// distance using index of points
int dist    (int i, int j) {
	return distance(x[i], y[i], x[j], y[j]);
}

// print car No.1
void print_one (int i) {
	while(i--) {printf("1\n");}
}

// print car No.2
void print_two (int i) {
	while(i--) {printf("2\n");}
}

// Reconstruct optimal solution and print car number of each case
void print_car_number (int i, int j) {
	if (i==0)       print_two(j);
	else if (j==0)  print_one(i);
	else if (i>j) {
		print_car_number (b[j+1][j], j);  
		print_one(i-j);
	} else {
		print_car_number (i, b[i][i+1]);
		print_two(j-i);
	}
}

int main() {

	// N = the length of row and column, W = the number of cases
	int N, W, i, j;
	scanf("%d%d", &N, &W);

	// (x[i-1], y[i-1]) means x and y-coordinate of the i-th point
	for (i=0; i<W; i++)
		scanf("%d%d", &x[i], &y[i]);

	int cur, min, min_idx;
	d[0][0] = 0;

	// bottom-up dynamic programming. 
	for (i=0; i<W; i++) {

		/* column-wise calculation (Upper triangle part)  */

		// Calculate diagonal-neighbor elements
		min = d[i][0] + distance (N, N, x[i], y[i]);
		min_idx = 0;
		for (j=1; j<i; j++) {
			cur = d[i][j] + dist(j-1,i);
			if (min > cur) {
				min = cur;
				min_idx = j;
			}
		}
		if (i==0) 
			d[0][1] = distance(N, N, x[0], y[0]); // p2
		else {
			d[i][i+1] = min;
			b[i][i+1] = min_idx;
		}

		// fill the remaining elements
		for (j=i+2; j<=W; j++)
			d[i][j] = d[i][j-1] + dist(j-2,j-1);

		/* row-wise calculation (Lower triangle part) */

		// Calculate diagonal-neighbor elements
		min = d[0][i] + distance(1, 1, x[i], y[i]);
		min_idx = 0;
		for (j=1; j<i; j++) {
			cur = d[j][i] + dist(j-1,i);
			if (min > cur) {
				min = cur;
				min_idx = j;
			}
		}
		if (i==0)
			d[1][0] = distance(1, 1, x[0], y[0]); // p1
		else {
			d[i+1][i] = min;
			b[i+1][i] = min_idx;
		}

		// fill the remaining elements
		for (j=i+2; j<=W; j++)
			d[j][i] = d[j-1][i] + dist(j-2,j-1);
	}

	/* find minimum */

	min = d[0][W];
	int min_i=0, min_j=W;
	for (i=1; i<W; i++)
		if (min > d[i][W]) {
			min = d[i][W];
			min_i = i;      
		}
	for (i=0; i<W; i++)
		if (min > d[W][i]) {
			min = d[W][i];
			min_i = W;
			min_j = i;
		}

	// Print optimal solution
	printf("%d\n",min);

	// Reconstruct optimal solution and print car numbers of each cases
	print_car_number(min_i, min_j);

	return 0;
}
