#include <iostream>
#include <cstring>
#define MOD 10000000
using namespace std;
int C;
int cache[101][101];

// n means the number of remaining blocks
// m means the number of current row blocks
int poly (int n, int m) {
    if (n == 0) return 1;
    int &ret = cache[n][m];
    if (ret != -1) return ret;
    ret = 0;
    if (m == 0) {
        for (int i=1; i<=n; ++i) {
            ret = (ret + poly(n-i,i))%MOD;
        }
        return ret;
    }
    for (int i=1; i<=n; ++i) {
        ret += ((m+i-1)*poly(n-i,i))%MOD;
        ret = ret % MOD;
    }
    return ret;
}

int main() {
    cin >> C;
    int n;
    memset(cache,-1,sizeof(cache));
    while (C--) {
        cin >> n;
        cout << poly(n,0) << endl;
    }
}
