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

int t, n, x;

void solve () {
    cin >> n >> x;
    vector<int> s(n);
    for (int i=0; i<n; i++) scanf("%d", &s[i]);
    sort(s.begin(), s.end());
    int l = 0, r = n-1;
    int cnt = 0;
    while (l <= r) {
        if (s[r] + s[l] <= x) {
            l++;
        }
        r--;
        cnt++;
    }
    cout << cnt;
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
