#include <iostream>
#define MOD 1000000007
using namespace std;
int C,n;


int main() {
    cin >> C;
    int fib[101] = {1, 2};
    for (int i=2; i<100; ++i) {
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
    }
    while (C--) {
        cin >> n;
        int res = fib[n-1];
        if (n <= 2) {
            cout << 0 << endl;
            continue;
        }
        if (n%2 == 1) res -= fib[n/2-1];
        else res = res -= (fib[n/2-1] + fib[n/2-2]);
        while (res < 0) { res += MOD; }
        cout << res << endl;
    }
}
