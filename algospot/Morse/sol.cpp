#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 1000000001
#define LEN 200
using namespace std;
int C;
// number of combinations
long long cache[LEN+1][LEN+1];
string kth (int n, int m, int k) {
    if (n == 0)
        return string(m, 'o');
    if (k <= cache[n+m-1][n-1]) {
        return "-" + kth(n-1,m,k);
    } else {
        return "o" + kth(n, m-1, k-cache[n+m-1][n-1]);
    }
}
int main() {

    // build combinations
    memset(cache,0,sizeof(cache));
    for (int n=0; n<=LEN; ++n)
        cache[n][0] = 1;
    for (int n=1; n<LEN; ++n)
        for (int m=1; m<=n; ++m) {
            cache[n][m] = cache[n-1][m-1] + cache[n-1][m];
            if (cache[n][m] > MAX)
                cache[n][m] =MAX;
        }
    cin >> C;
    int n, m, k;
    while (C--) {
        cin >> n >> m >> k;
        cout << kth(n,m,k) << endl;
    }
}
