#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 5e18


string cake[50];

void solve () {
    int r, c;
    cin >> r >> c;
    for (int i=0; i<r; i++)
        cin >> cake[i];

    // vertical expansion
    for (int i=0; i<c; i++) {
        int j = 0;
        while(true) {
            if (j == r) break;
            if (cake[j][i] != '?') {
                for (int k=j-1; k>=0 && cake[k][i] == '?'; k--) {
                    cake[k][i] = cake[j][i];
                }
            }
            j++;
        }
        j = 0;
        while (j<r && cake[j][i] != '?') {
            j++;
        }
        if (j==0 || j==r) continue;
        for (int k=j; k<r; k++) {
            cake[k][i] = cake[j-1][i];
        }
    }


    // horizontal expansion
    int i=0;
    while (true) {
        if (i == c) break;
        if (cake[0][i] != '?') {
            for (int k=i-1; k>=0 && cake[0][k] == '?'; k--) {
                for (int j=0; j<r; j++) {
                    cake[j][k] = cake[j][i];
                }
            }
        }
        i++;
    }
    i = 0;
    while(i<c && cake[0][i] != '?') { i++; }
    if (i < c) {
        for (int j=i; j<c; j++) {
            for (int k=0; k<r; k++) {
                cake[k][j] = cake[k][i-1];
            }
        }
    }
    for (int i=0; i<r; i++)
        cout << cake[i] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << endl;
        solve();
    }
    return 0;
}
