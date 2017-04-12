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


int t, n, a, b, c;
bool d[3000];
void read() {
    memset(d,false,sizeof(d));
    cin >> n;
    for (int i=0; i<n*(2*n-1); i++) {
        scanf("%d", &a);
        d[a] = !d[a];
    }
}

void solve () {
    for (int i=1; i<=2500; ++i)
        if (d[i])
            printf("%d ", i);
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        read();
        solve();
        cout << endl;
    }
    return 0;
}
