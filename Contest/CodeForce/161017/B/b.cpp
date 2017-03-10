#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[501];
#define INF 98765431
int k;

int main () {
    int n;
    scanf("%d%d",&n,&k);
    for (int i=1; i<=n; i++)  {
        scanf("%d",&a[i]);
    }
    int cnt = 0;
    for (int i=2; i<=n; i++) {
        int diff = k-a[i-1]-a[i];
        if (diff > 0) {
            cnt += diff;
            a[i] += diff;
        }
    }

    printf("%d\n", cnt);
    for (int i=1; i<=n; i++)
        printf("%d ", a[i]);

    return 0;
}
