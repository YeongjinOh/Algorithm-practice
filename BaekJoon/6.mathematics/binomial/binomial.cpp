#include <cstdio>
#define divisor 1000000007
#define MAX 2000000
using namespace std;
long long fact[MAX];

long long pow (int base, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return (long long) base;
    long long half = pow (base, n/2);
    if (n%2 == 0) {
        return (half * half)%divisor;
    }
    return (((half * half)%divisor)*(long long)base)%divisor;
}

long long inverse(int base) {
    return pow (base,divisor-2);
}

void build_fact () {
    long long i;
    fact[0]=1;
    for (i=1; i<MAX; i++) {
        fact[i] = (fact[i-1]*(i+1))%divisor;
    }
}

// return nCr -1
long long choose (int n, int r) {
    long long c = fact[n-1];
    c = (c * inverse(fact[r-1]))%divisor;
    c = (c * inverse(fact[n-r-1]) - 1)%divisor;
    return c;
}

int main() {
    int n, m, T;
    build_fact();
    scanf("%d", &T);
    for (int i=1; i<=T; i++) {
        scanf("%d%d", &n, &m);
        printf("Case #%d\n%lld\n", i, choose(m+n+2,n+1));
    }
    return 0;
}
