#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <assert.h>
using namespace std;

int ind[1000], r[1000];


bool comp(int a, int b)
{
	return r[a] > r[b];
}

int rx[1000], ry[1000];

int main() {
	int tc, N, A;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen)
	{
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		for (int i=0; i<n; ++i) {
			scanf("%d", &r[i]);
			ind[i] = i;
		}
		sort(ind, ind+n, comp);
		rx[ind[0]] = ry[ind[0]] = 0;
		int dimX = r[ind[0]];
		int posX = 0;
		int posY = 0;
		int dimY = r[ind[0]];
		for (int i=1; i<n; ++i)
		{
			int cur = ind[i];
			if (dimY + r[cur] > y)
			{
				// start new row
				posX = dimX + r[cur];
				dimX += 2 * r[cur];
				dimY = r[cur];
				posY = 0;
			}
			else {
				posY = dimY + r[cur];
				dimY += 2 * r[cur];
			}
			assert(posX <= x && posY <= y);
			rx[cur] = posX;
			ry[cur] = posY;
		}
		printf("Case #%d:", scen);
		for (int i=0; i<n; ++i)
			printf(" %d %d", rx[i], ry[i]);
		puts("");
	}
	return 0;
}
