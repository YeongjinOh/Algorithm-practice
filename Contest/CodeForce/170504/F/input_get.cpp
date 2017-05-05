#include <iostream>

using namespace std;
#define LEN 100005
int p[LEN];

int n = 100000, m = 50000, q = 100000;

int Find (int i) {
    return p[i] == i? i: p[i] = Find(p[i]);
}

int getRand() {
    return rand()%n+1;
}

int main() {
    for (int i=1; i<=n; i++) p[i] = i;
    printf("%d %d %d\n", n, m, q);
    while (m > 0) {
        int a = getRand(), b = getRand();
        while(Find(a) == Find(b)) {
            a = getRand(), b = getRand();
        }
        p[a] = b;
        printf("%d %d\n", a, b);
        m--;
    }
    for (int i=0; i<q; i++) {
        int a = getRand(), b = getRand();
        while (a == b) {
            b = getRand();
        }
        printf("%d %d\n", a, b);
    }

}
