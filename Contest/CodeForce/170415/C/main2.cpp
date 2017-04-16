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
string str;
int n;
vector<char> t;

int main() {
    cin >> str;
    n = str.size();
    vector<char> best(n+1);
    best[n] = 'z'+1;
    for (int i=n-1; i>=0; i--) {
        best[i] = min<char>(best[i+1],str[i]);
    }
    for (int i=0; i<n; i++) {
        while (t.size() > 0 && t.back() <= best[i]) {
            cout << t.back();
            t.pop_back();
        }
        if (str[i] == best[i]) cout << str[i];
        else t.push_back(str[i]);
    }
    while (t.size() > 0) {
        cout << t.back();
        t.pop_back();
    }
    cout << endl;
    return 0;
}
