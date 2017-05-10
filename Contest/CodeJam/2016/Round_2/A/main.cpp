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
#define fi first
#define se second
#define INF 5e18


int t;
map<vector<int>, string> mp;

int getIdx(char c) {
    if (c == 'R') return 0;
    if (c == 'P') return 1;
    return 2;
}
int getNextIdx(char c) {
    if (c == 'R') return getIdx('S');
    if (c == 'S') return getIdx('P');
    return getIdx('R');
}
void build() {
    map<char, string> gen;
    gen['R'] = "RS";
    gen['S'] = "PS";
    gen['P'] = "PR";
    string bases[] = {"R", "P", "S"};
    for (int b=0; b<3; b++) {
        string base = bases[b];
        vector<int> cnt(3,0);
        cnt[getIdx(base[0])] = 1;
        mp[cnt] = base;
        for (int i=1; i<=12; i++) {
            string res = "";
            for (int j=0; j<base.size(); j++) {
                res += gen[base[j]];
                cnt[getNextIdx(base[j])]++;
            }
            mp[cnt] = res;
            base = res;
        }
    }
}

string getSort(string str, int start, int end) {
    if (end-start == 1) return str.substr(start,1);
    int mid = (start+end)/2;
    string s1 = getSort(str,start,mid), s2 = getSort(str,mid,end);
    if (s1 > s2)
        return s2+s1;
    else
        return s1+s2;
}

string getSort(string str) {
    return getSort(str, 0, str.size());
}

void solve () {
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    vector<int> cnt(3,0);
    cnt[0] = r;
    cnt[1] = p;
    cnt[2] = s;
    if (mp.find(cnt) == mp.end()) cout << "IMPOSSIBLE";
    else cout << getSort(mp[cnt]);
}

int main() {
    cin >> t;
    build();
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
