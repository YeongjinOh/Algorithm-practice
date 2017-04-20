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

int get(string str) {

    int cnt = 0;
    for (int i=0; i<str.size()-1; i++) {
        if (str[i] == 'V' && str[i+1] == 'K') cnt++;
    }
    return cnt;
}

int main() {
    string str;
    cin >> str;
    int res = get(str);
    for (int i=0; i<str.size(); i++) {
        string cp = str;
        cp[i] = (cp[i] == 'K'?'V':'K');
        res = max<int>(res, get(cp));
    }
    cout << res << endl;
    return 0;
}
