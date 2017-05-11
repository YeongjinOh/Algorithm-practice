#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
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


char buf[20000];
int t;
char buffer[11000];

map<string,int> lang;

void backtrack(vector<vector<string> > sentances, int idx, int cnt, int &res) {
    if (cnt > res) return;
    if (idx == sentances.size()) {
        res = min(res, cnt);
        return;
    }
    vector<int> backup;
    vector<string> &stc = sentances[idx];
    int n = stc.size();
    for (int i=0; i<n; i++) {
        backup.push_back(lang[stc[i]]);
    }
    int cntEng = cnt, cntFre = cnt;
    // English
    for (int i=0; i<n; i++) {
        string &word = stc[i];
        if (lang[word] == 0) {
            lang[word] = 1;
        } else if (lang[word] == 2) {
            lang[word] = 3;
            cntEng++;
        }
    }
    backtrack(sentances, idx+1, cntEng, res);
    for (int i=0; i<n; i++) lang[stc[i]] = backup[i]; // backup
    // French
    for (int i=0; i<n; i++) {
        string &word = stc[i];
        if (lang[word] == 0) {
            lang[word] = 2;
        } else if (lang[word] == 1) {
            lang[word] = 3;
            cntFre++;
        }
    }
    backtrack(sentances, idx+1, cntFre, res);
    for (int i=0; i<n; i++) lang[stc[i]] = backup[i]; // backup
}

void solve () {
    int n; cin >> n; gets(buffer);
    lang.clear();
    vector<vector<string> > sentances(n);
    for (int i=0; i<n; i++) {
        gets(buffer);
        string s = buffer;
        istringstream ss(s);
        while (ss >> s) sentances[i].push_back(s);
    }
    int cnt = 0;
    for (int i=0; i<sentances[0].size(); i++)
        lang[sentances[0][i]] = 1;
    for (int i=0; i<sentances[1].size(); i++) {
        if (lang[sentances[1][i]] == 0) {
            lang[sentances[1][i]] = 2;
        } else if (lang[sentances[1][i]] == 1) {
            cnt++;
            lang[sentances[1][i]] = 3;
        }
    }
    int res = 987654321;
    backtrack(sentances, 2, cnt, res);
    cout << res;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
