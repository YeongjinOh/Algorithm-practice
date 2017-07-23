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
#define LEN 100005

vector<int> getPartialMatch (char t[], int m) {
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (t[begin+matched] == t[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        } else if (matched == 0) {
            begin++;
        } else {
            begin += matched - pi[matched-1];
            matched = pi[matched-1];
        }
    }
    return pi;
}

int main() {
    char s[LEN], t[LEN];
    gets(s); gets(t);
    int n = strlen(s), m = strlen(t);
    int res = 0;
    vector<int> pi = getPartialMatch(t, m);
    int k = m - pi[m-1], cnt = 0;

    /*
    vector<bool> match(n, false);
    for (int begin=0; begin <= n-m; begin++) {
        match[begin] = true;
        for (int matched = 0; matched < m && match[begin]; matched++)
            if (s[begin+matched] != '?' && s[begin+matched] != t[matched])
                match[begin] = false;
    }
    */

    vector<vector<int> > dp(n, vector<int> (m, 0));
    int begin = 0, matched = 0, lastIdx = -1, res = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // TODO
        }
    }
    while (begin <= n-m) {
        if (matched < m && (s[begin+matched] == '?' || s[begin + matched] == t[matched])) {
            ++matched;
            if (matched == m) {
                cnt++;
                for (int i=max(begin,lastIdx+1); i<begin+matched; i++) {
                    s[i] = t[i-begin];
                }
                lastIdx = begin+matched-1;
            }
        } else {
            begin++;
            matched = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
