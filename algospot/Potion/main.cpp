#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 201

using namespace std;
int C,n;
int r[LEN], p[LEN];

int gcd (int a, int b) { return b==0?a:gcd(b,a%b); }

// return ceil(a/b)
int ceil (int a, int b) {
    return (a+b-1)/b;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> r[i];
        for (int i=0; i<n; i++) cin >> p[i];
        int gcdr = r[0];
        for (int i=1; i<n; i++) {
            gcdr = gcd(gcdr,r[i]);
        }
        bool over = false;
        for (int i=0; i<n; i++) {
            if (r[i] < p[i])
                over = true;
        }
        if (!over) {
            for (int i=0; i<n; i++)
                cout << (r[i] - p[i]) << " ";
            cout << endl;
            continue;
        }
        int times = 0;
        for (int i=0; i<n; i++) {
            r[i] /= gcdr;
            times = max<int>(times, ceil(p[i],r[i]));
        }
        for (int i=0; i<n; i++) {
            cout << (r[i]*times - p[i]) << " ";
        }
        cout << endl;
    }
}
