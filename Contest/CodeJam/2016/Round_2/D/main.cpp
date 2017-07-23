#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
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


int t, n;

int parent[30];
int groupCnt[30];
int sizeDiff[30];
vector<int> group[30];

int find(int here) {
    if (parent[here] == here) return here;
    return parent[here] = find(parent[here]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    parent[a] = b;
}

void solve () {
    int cnt = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        parent[i] = i;
        groupCnt[i] = 0;
        group[i].clear();
    }
    vector<vector<bool> > ab(n, vector<bool> (n, false)); // able
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char c; cin >> c;
            if (c == '1') {
                ab[i][j] = true;
                cnt++;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int l=0; l<j; l++) {
                if (ab[i][l] && ab[i][j])
                    merge(l,j);
            }
        }
    }
    for (int i=0; i<n; i++)
        group[find(i)].pb(i);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (ab[i][j]) {
                int p = find(j);
                groupCnt[p]++;
                break;
            }
        }
    }
    for (int i=0; i<n; i++) {
        // number of machine : group[i].size()
        // number of person : groupCnt[i]
        if (i == find(i)) {
            sizeDiff[i] = group[i].size() - groupCnt[i];
        }
    }
   int goalSum = 0, tmpSz = 0;
    for (int i=0; i<n; i++) {
        if(i == find(i)) {
            int sz = group[i].size();
            if (groupCnt[i] > sz) {
                goalSum -= groupCnt[i] - sz;
                sz = groupCnt[i];
                printf("%d\n", sz);
            }
            goalSum += sz*sz;
        }
    }
    if (tmpSz > n) goalSum = n*n;
    cout << goalSum-cnt << endl;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
