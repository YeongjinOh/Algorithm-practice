#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10000001
using namespace std;

int minFactor[MAX], numFactors[MAX];

int main() {
    int C, n, lo, hi;

    // build minFactor
    memset(minFactor,-1,sizeof(minFactor));
    for (int i=2; i*i<MAX; i++) {
        if (minFactor[i] == -1) {
            for (int j=i*i; j<MAX; j+=i) {
                if (minFactor[j] == -1)
                    minFactor[j] = i;
            }
        }
    }

    // build number of factors
    memset(numFactors,0,sizeof(numFactors));
    numFactors[1] = 1;
    for (int i=2; i<MAX; i++) {
        if (minFactor[i] == -1) {
            numFactors[i] = 2;
        } else {
            int factor = minFactor[i], cnt = 0;
            int num = i;
            while (num % factor == 0) {
                num /= factor;
                cnt++;
            }
            numFactors[i] = numFactors[num] * (cnt + 1);
        }
    }
    cin >> C;
    while (C--) {
        cin >> n>> lo >> hi;
        int cnt = 0;
        for (int i=lo; i<=hi; i++) {
            if (numFactors[i] == n)
                cnt++;
        }
        cout << cnt << endl;
    }
}
