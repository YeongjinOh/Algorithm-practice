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

int t, n, p;
int r[55];
vector<pair<int, int> > q[55];

void solve () {
    cin >> n >> p;
    for (int i=0; i<n; i++)
        scanf("%d", &r[i]);
    for (int i=0; i<n; i++) {
        q[i].clear();
        for (int j=0; j<p; j++) {
            int qq;
            cin >> qq;
            int lb = (10*qq)/(11*r[i]), ub = (10*qq)/(9*r[i]);
            if ((10*qq)%(11*r[i]) != 0) lb++;
            q[i].push_back(make_pair(lb,ub));
        }
        sort(q[i].begin(), q[i].end());
    }
    int res = 0;
    vector<int> ptr(n, 0);
    // gready하게 range pair 들의 교집합이 있는 조합을 찾는다.
    while(true) {
        int minUb = 987654321, maxLb = 0;
        int minIdx = 0, maxIdx = 0;
        for (int i=0; i<n; i++) {
            if (q[i][ptr[i]].first > maxLb) {
                maxLb = q[i][ptr[i]].first;
                maxIdx = i;
            }
            if (q[i][ptr[i]].second < minUb) {
                minUb = q[i][ptr[i]].second;
                minIdx = i;
            }
        }
        if (q[minIdx][ptr[minIdx]].second >= q[maxIdx][ptr[maxIdx]].first) {
            res++;
            for (int i=0; i<n; i++)
                ptr[i]++;
        } else {
            ptr[minIdx]++;
        }
        bool finish = false;
        for (int i=0; i<n; i++) {
            if (ptr[i] == p)
                finish = true;
        }
        if (finish) break;
    }
    cout << res;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
