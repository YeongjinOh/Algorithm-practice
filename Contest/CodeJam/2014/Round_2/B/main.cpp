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
void solve () {
    int res = 0;
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<int> cp = a;
    sort(cp.begin(), cp.end());
    int l = 0, r = n-1;
    for (int i=0; i<n-1; i++) {
        int idx = 0;
        while (a[idx] != cp[i]) { idx++; }
        if (idx-l < r-idx) {
            while (l < idx) {
                swap(a[idx], a[idx-1]);
                idx--;
                res++;
            }
            l++;
        } else {
            while (idx < r) {
                swap(a[idx], a[idx+1]);
                idx++;
                res++;
            }
            r--;
        }
    }
    cout << res;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
//        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
