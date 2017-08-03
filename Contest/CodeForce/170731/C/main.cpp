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

int n, q, c;
int dp[11][101][101];
int main() {
    scanf("%d%d%d", &n, &q, &c);
    c++;
    memset(dp,0,sizeof(dp));
    for (int i=0; i<n; i++) {
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        for (int j=0; j<c; j++) {
            dp[j][x][y] += (s+j)%c;
        }
    }

    while(q--) {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        ll sum = 0;
        for (int x=x1; x<=x2; x++) {
            for (int y=y1; y<=y2; y++) {
                sum += dp[t%c][x][y];
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
