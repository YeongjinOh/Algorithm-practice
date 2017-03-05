#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 2000000000
int C;

int winRatio (double a, double b) {
    return (a*100)/b;
}
int main() {
    cin >> C;
    while (C--) {
        long long n, m;
        cin >> n >> m;
        if (winRatio(m,n) == winRatio(m+MAX,n+MAX)) {
            cout << -1 << endl;
            continue;
        }
        long long l = 0, r = MAX;
        while (l<r) {
            long long mid = (l+r)/2;
            if (winRatio(m,n) < winRatio(m+mid,n+mid)) r = mid;
            else l = mid+1;
        }
        cout << l << endl;
    }
}
