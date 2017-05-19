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
    char ss[LEN], s[LEN], t[LEN];
    gets(ss); gets(t);
    int n = strlen(ss), m = strlen(t);
    vector<int> pi = getPartialMatch(t, m);
    int res = 0;
    for (int bg=0; bg<m; bg++) {
        strcpy(s,ss);
        int begin = bg, matched = 0, cnt = 0, lastIdx = -1, lastMatched = 0;
        while (begin <= n-m) {
            if (matched < m && (s[begin+matched] == '?' || s[begin + matched] == t[matched])) {
                ++matched;
                if (s[begin + matched] == t[matched])
                    lastMatched = matched;
                if (matched == m) {
                    cnt++;
                    for (int i=max(begin,lastIdx+1); i<begin+matched; i++) {
                        s[i] = t[i-begin];
                    }
                    lastIdx = begin+matched-1;
                }
            } else if (lastMatched == 0) {
                begin++;
                matched = 0;
            } else {
                begin += lastMatched - pi[lastMatched-1];
                lastMatched = pi[lastMatched-1];
                matched = lastMatched;
            }
            res = max(res,cnt);
        }
    }
    cout << res << endl;
    return 0;
}
