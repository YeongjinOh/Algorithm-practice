#include <stdio.h>

int max (int a, int b) { return a>b?a:b; }

int main() {
	
	// number of glasses
	int n, i;
	scanf("%d", &n);

	// oo means drinking both previous and current wine
	// ox means not drinking current wine
	// xo means not drinking previous wine 
	// xx means drinking neight previous nor current wine
	int	cur, oo=0, xo=0, ox=0, xx=0, prev_ox, prev_xx;
	for (i=0; i<n; i++) {
		
		scanf("%d", &cur);

		prev_ox = ox;
		prev_xx = xx;
		ox = max(oo, xo);
		oo = xo + cur;
		xx = max(prev_ox, prev_xx);
		xo = max(prev_ox, prev_xx) + cur;
	}
	
	printf("%d\n",max(max(oo,xo),ox));			

}
