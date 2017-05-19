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

#define LEN 105
#define MAX 200005
int p[LEN], c[LEN], l[LEN];
int n, k;
bool isPrime[MAX];
bool done;

void backtrack(vector<pii> &pc, vector<bool> visit, int pos, ll pSum) {
    if (done) return;
    if (pSum >= k) {
        done = true;
        return;
    }
    if (pos == pc.size()) {
        return;
    }
    ll tmpSum = 0;
    for (int i=pos; i<pc.size(); i++) {
        if (!visit[i]) tmpSum += pc[i].fi;
    }
    if (pSum + tmpSum < k) return;
    for (int i=pos; i<pc.size(); i++) {
        if (visit[i]) continue;
        int curMagic = pc[i].se;
        vector<bool> cp = visit;
        for (int j=i+1; j<pc.size(); j++) {
            if (isPrime[pc[j].se + curMagic])
                cp[j] = true;
        }
        backtrack(pc, cp, i+1, pSum + pc[i].fi);
    }
}

bool check(int m) {
    vector<pii> pc;
    for (int i=0; i<n; i++) if (l[i] <= m) pc.pb(mp(p[i],c[i]));
    vector<bool> visit(pc.size(), false);
    sort(all(pc));
    reverse(all(pc));
    done = false;
    backtrack(pc, visit, 0, 0);
    return done;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d%d%d", &p[i], &c[i], &l[i]);
    }
    // build isPrime
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i*i<MAX; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<MAX; j+=i)
                isPrime[j] = false;
        }
    }

    // bisection
    int l=1, r=n+1;
    while (l<r) {
        int mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    if (l > n) l = -1;
    cout << l << endl;
    return 0;
}
