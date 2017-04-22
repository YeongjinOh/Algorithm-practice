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
int a[100005], b[100005];
bool use[100005];
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) scanf("%d", &b[i]);
    vector<pair<int, pair<int, int> > >  pq;
    for (int i=0; i<n; i++) pq.pb(mp(a[i], mp(b[i], i)));
    vector<int> sol;
    sort(all(pq));
    reverse(all(pq));
    sol.pb(pq[0].se.se);
    for (int i=2; i<pq.size(); i+=2) {
        if (pq[i-1].se.fi < pq[i].se.fi) sol.pb(pq[i].se.se);
        else sol.pb(pq[i-1].se.se);
    }
    if (pq.size()%2 == 0) sol.pb(pq.back().se.se);
    cout << sol.size() << endl;
    for (int i=0; i<sol.size(); i++) printf("%d ", sol[i]+1);

    return 0;
}
