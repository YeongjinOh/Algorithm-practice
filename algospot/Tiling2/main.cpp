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
        cout << fib[n-1] << endl;
    }
}
