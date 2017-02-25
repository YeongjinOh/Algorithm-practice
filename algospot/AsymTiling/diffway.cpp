#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;
int C;
int cache[105];
int fib[101] = {0, 1, 2};

// o means one vertical blokc
// t means two horizontal blocks
// case a) o ~ o
//      b) t ~ t
//      c) o ~ t
//      d) t ~ o
int asym(int n) {
    if (n<3) return 0;
    if (n==3) return 2;

    int &ret = cache[n];
    if (ret != -1) return ret;

    // case a) + b)
    ret = (asym(n-2) + asym(n-4))%MOD;

    // case c) + d)
    ret += (2*fib[n-3])%MOD;
    ret = ret%MOD;
    return ret;
}

int main() {
    cin >> C;
    for (int i=3; i<=100; ++i) {
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
    }
    int n;
    while (C--) {
        cin >> n;
        memset(cache,-1,sizeof(cache));
        cout << asym(n) << endl;
    }
}
