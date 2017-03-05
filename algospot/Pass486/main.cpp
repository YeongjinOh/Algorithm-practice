#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10000001
using namespace std;

int minFactor[MAX];

// check if the number of factors of num = n
bool check(int n, int num) {
    // factor, num
    while (minFactor[num] != -1) {
        int cnt = 0;
        int factor = minFactor[num];
        while (num % factor == 0) {
            cnt++;
            num /= factor;
        }
        if (cnt > 0) {
            if (n % (cnt+1) != 0) return false;
            n /= (cnt+1);
        }
    }
    if (num > 1) {
        return n == 2;
    }
    return n == 1;
}

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
    cin >> C;
    while (C--) {
        cin >> n>> lo >> hi;
        int cnt = 0;
        for (int i=lo; i<=hi; i++) {
            if (check(n, i))
                cnt++;
        }
        cout << cnt << endl;
    }
}
