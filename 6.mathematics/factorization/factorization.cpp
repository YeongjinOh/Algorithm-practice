#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
#define MAX 10000010

// -1 means prime
// 0 or positive means the smallest prime factor
int isPrime[MAX];

int main () {
    int n;
    cin >> n;

    memset(isPrime,-1,sizeof(isPrime));

    // sieve of eratoshenes
    for (int i=2; i*i<=n; i++) {
        if (isPrime[i] == -1) {
            for (int j=i*i; j<=n; j+=i)
                if (isPrime[j] == -1)
                    isPrime[j] = i;
        }
    }
    while (isPrime[n] != -1) {
        cout << isPrime[n] << endl;
        n /= isPrime[n];
    }
    cout << n << endl;

    return 0;
}
