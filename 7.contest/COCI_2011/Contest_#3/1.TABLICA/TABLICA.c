#include <stdio.h>

int main() {
	int A, B, C, D;

	scanf("%d%d%d%d",&A,&B,&C,&D);
	int i, tmp, cnt = 0;
	double cur, max = (double)A/C + (double)B/D;

	// rotate and find maximum
	for (i=1; i<=3; i++) {
		tmp = A; A = C;	C = D; D = B;	B = tmp;
		cur = (double)A/C + (double)B/D;
		if (max < cur)	{
			max = cur;
			cnt = i;
		}
	}
	printf("%d", cnt);
}
