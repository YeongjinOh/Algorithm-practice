#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
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

bool isPal(string str) {
    for (int i=0; i<str.size(); i++) {
        if (str[i] != str[str.size()-1-i]) return false;
    }
    return true;
}

bool isCanPal(string str) {
    for (int i=0; i<str.size(); i++) {
        string cp = str;
        for (char c='a'; c<='z'; c++) {
            if (str[i] == c)
                continue;
            cp[i] = c;
            if (isPal(cp)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    string str;
    cin >> str;

    if (isCanPal(str)) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}
