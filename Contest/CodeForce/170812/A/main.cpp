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

int n,k ;

int main() {
    scanf("%d%d", &n, &k);
    vector<int> cand;
    for (int i=0; i<n ; i++) {
        int candy;
        scanf("%d", &candy);
        cand.pb(candy);
    }
    int has = 0;
    for (int days = 1; days <= n; days++) {
        has += cand[days-1];
        int take = min(8,has);
        has -= take;
        k -= take;
        if (k <= 0) {
            cout << days << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
