#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
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

int n, w;
int a[105], b[105];

int main() {
    scanf("%d%d", &n, &w);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<pii> pa;
    for (int i=0; i<n; i++) {
        pa.pb(mp(a[i],i));
    }
    sort(all(pa));
    reverse(all(pa));
    for (int i=0; i<n; i++) {
        int half = (a[i]+1)/2;
        if (half > w) {
            cout << -1 << endl;
            return 0;
        }
        w -= half;
        b[i] = half;
    }
    for (int i=0; i<n; i++) {
        int idx = pa[i].se;
        int rem = a[idx] - b[idx];
        if (rem > w) {
            b[idx] += w;
            w = 0;
            break;
        }
        b[idx] += rem;
        w -= rem;
    }
    for (int i=0; i<n; i++)
        printf("%d ", b[i]);
    return 0;
}
