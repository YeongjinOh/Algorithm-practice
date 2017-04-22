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
int n;
int a[500005], p[500005], c[500005];
int res[500005];
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    memset(res, 0, sizeof(res));
    memset(p, 0, sizeof(p));
    memset(c, 0, sizeof(c));
    // build parent, child
    for (int i=1; i<=n; i++) {
        if (a[i] != -1) {
            p[i] = a[i];
            c[a[i]] = i;
        }
    }
    int l = 1, r = n;
    for (int i=1; i<=n; i++) {
        if (res[i] == 0) {
            //find child
            int cur = i;
            while (c[cur]) {
                cur = c[cur];
            }
            while (p[cur]) {
                res[cur] = l++;
                cur = p[cur];
            }
            res[cur] = r--;
        }
    }
    for (int i=1; i<=n; i++) printf("%d ", res[i]);
    cout << endl;
    return 0;
}
