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

int n, len;
vector<bool> isGood(26, false);

string pattern;
bool isStar = false;
int starIdx = 0;

bool match(string &str) {
    int m = sz(str);
    if (!isStar && m != len) return false;
    if (sz(str) < len-1) return false;
    for (int i=0; i<starIdx; i++) {
        if (pattern[i] == '?') {
            if (!isGood[str[i]-'a']) return false;
        } else if (pattern[i] != str[i]) {
            return false;
        }
    }
    if (!isStar) return true;
    for (int i=starIdx+1; i<len; i++) {
        if (pattern[i] == '?') {
            if (!isGood[str[i+m-len]-'a']) return false;
        } else if (pattern[i] != str[i+m-len]) {
            return false;
        }
    }
    for (int i=starIdx; i<=starIdx+m-len; i++) {
        if (isGood[str[i]-'a']) return false;
    }
    return true;
}

int main() {
    string goodStr;
    cin >> goodStr;
    for (int i=0; i<sz(goodStr); ++i) {
        isGood[goodStr[i]-'a'] = true;
    }
    cin >> pattern;
    for (int i=0; i<sz(pattern); ++i) {
        if (pattern[i] == '*') {
            isStar = true;
            starIdx = i;
            break;
        }
    }
    len = sz(pattern);
    if (!isStar) starIdx = len;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        if (match(str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
