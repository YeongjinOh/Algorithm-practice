#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int C;

int main() {
    cin >> C;
    while (C--) {
        long long n, m;
        cin >> n >> m;
        long long a = (m*100)/n;
        if (a >= 99) {
            cout << -1 << endl;
            continue;
        }
        long long cmp = (a+1)*n - 100*m;
        double sol = (double)cmp/(99-a);
        if (cmp % (99-a) != 0)
            sol++;
        cout << (int)sol << endl;
    }
}
