#include <iostream>
#include <cstring>
#include <istream>
#include <sstream>
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
#define double long double // use long double when using bisection

// read string parsed by white space
void readStrings() {
    int n; cin >> n;
    char buffer[10000];
    gets(buffer);
    vector<vector<string> > sentances(n);
    for (int i=0; i<n; i++) {
        gets(buffer);
        string word = buffer;
        istringstream ss(word);
        while (ss >> word) sentances[i].push_back(word);
    }
}

int t;
void solve (int tc) {
    int n, p;
    cin >> n >> p;
    vector<int> cnt(p, 0);
    for (int i=0; i<n; i++) {
        int tmp; scanf("%d", &tmp);
        cnt[tmp%p]++;
    }
    int res = cnt[0];
    if (p == 2) {
        res += (cnt[1]+1)/2;
    } else if (p == 3) {
        int mm = min(cnt[1], cnt[2]);
        res += mm;
        cnt[1] -= mm;
        cnt[2] -= mm;
        int mx = max(cnt[1], cnt[2]);
        if (mx > 0)
            res += (mx-1)/3 + 1;
    } else if (p == 4) {
        int mm = min(cnt[1], cnt[3]);
        res += mm;
        cnt[1] -= mm;
        cnt[3] -= mm;
        res += cnt[2]/2;
        cnt[2] = cnt[2]%2;
        int mx = max(cnt[1], cnt[3]);
        res += mx/4;
        if (mx%4 != 0 || cnt[2] == 1) res++;
        if (mx%4 == 3 && cnt[2] == 1) res++;
    }
    cout << res;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
        cout << endl;
//        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
