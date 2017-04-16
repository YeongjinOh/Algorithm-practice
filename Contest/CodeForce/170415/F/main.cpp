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

long long n,m;
ll abs(ll a) { return a>0?a:-a; }
int main() {
    cin >> n >> m;
    vector<int> x, p;
    map<int,int> pc;
    int a, b;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        x.push_back(a);
    }
    for (int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        if (pc[a] == 0)
            p.pb(a);
        pc[a] += b;
    }
    sort(x.begin(),x.end());
    sort(p.begin(),p.end());

    ll res = 0;
    for (int i=0; i<n; i++) {
        ll minAbs = -1, minIdx = 0;
        for (int j=0; j<p.size(); j++) {
            if (pc[p[j]] == 0) continue;
            ll curAbs = abs(p[j]-x[i]);
            if (minAbs == -1 || minAbs > curAbs) {
                minAbs = curAbs;
                minIdx = j;
            }
        }
        pc[p[minIdx]]--;
        res += minAbs;
    }
    cout << res << endl;
    return 0;
}
