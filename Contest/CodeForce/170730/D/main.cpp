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
#define LEN 35003
int n, k;
vector<int> cake;
int main() {
    scanf("%d%d", &n, &k);
    vector<vector<vector<int> > > dp(k, vector<vector<int> > (n, vector<int> (n, 0)));
    cake = vector<int>(n);
    for (int i=0; i<n; i++) scanf("%d", &cake[i]);
    for (int i=0; i<n; i++) {
        vector<bool> visit(n+1, false);
        int cnt = 0;
        for (int j=i; j<n; j++) {
            if (!visit[cake[j]]) {
                visit[cake[j]] = true;
                cnt++;
            }
            dp[0][i][j] = cnt;
        }
    }
    for (int s=1; s<k; s++) {
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                for (int k=i; k<j; k++) {
                    dp[s][i][j] = max(dp[s][i][j], dp[s-1][i][k] + dp[0][k+1][j]);
                }
            }
        }
    }
    cout << dp[k-1][0][n-1] << endl;
    return 0;
}
