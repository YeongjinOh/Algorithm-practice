#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000

unsigned char isPrime[MAX/8+1];

int main() {

    // build prime
    memset(isPrime, 255, sizeof(isPrime));
    isPrime[0] &= ~3;
    for (int i=2; i*i<=MAX; ++i) {
//        if (isPrime[i/8] & (1 << i%8)) {
        if (isPrime[i >> 3] & (1 << (i&7))) {
            for (int j=i*i; j<=MAX; j += i) {
                isPrime[j/8] &= ~(1 << j%8);
            }
        }
    }
    for (int i=0; i<=MAX; i++)
        if (isPrime[i/8] & (1 << (i%8)))
            printf("%d ",i);
    cout << endl;
    return 0;
}
