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

int n, k;
string str;

int main() {
    scanf("%d", &k);
    cin >> str;
    int n = 0;
    vector<int> cnt(10,0);
    for (int i=0; i<str.size(); i++) {
        n += str[i]-'0';
        cnt[str[i]-'0']++;
    }
    if (n >= k) {
        cout << 0 << endl;
    } else {
        ll diff = k-n;
        int res = 0;
        for (int i=0; i<10 && diff > 0; i++) {
            int div = 9-i;
            if (cnt[i]*div <= diff) {
                diff -= cnt[i]*div;
                res += cnt[i];
            } else {
                res += diff/div;
                if (diff%div != 0)
                    res++;
                diff = 0;
            }
        }
        cout << res << endl;
    }

    return 0;
}
