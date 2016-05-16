#include <stdio.h>

int main() {
	
	// E = K%15, S = K%28, M = K%19.
	// what we have to do is to find the smallest positive K
	int E, S, M;
	scanf("%d%d%d", &E, &S, &M);
	
	// first, find the smallest K for E,M
	while (E != M) {
		if (E<M)
			E+=15;
		else
			M+=19;
	}

	// find the smallest K for S, E(=M)
	while (S != E) {
		if (S<E)
			S+=28;
		else
			E+=15*19;
	}

	printf("%d\n", E);
}
