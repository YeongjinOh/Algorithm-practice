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


int t;
void solve () {
    int n; cin >> n;
    vector<int> cnt(n);
    rep(i,0,n) cin >> cnt[i];
    int sum = 0;
    rep(i,0,n) sum += cnt[i];
    bool jump = true;
    while(sum--) {
        int mx = 0;
        for (int i=1; i<n; i++) {
            if (cnt[i] > cnt[mx]) mx = i;
        }
        cnt[mx]--;
        if (cnt[mx]*2 > sum-1) jump = true;
        if (jump) {
            printf("%c", 'A'+mx);
            jump = false;
        } else {
            printf(" %c", 'A'+mx);
        }
    }
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
