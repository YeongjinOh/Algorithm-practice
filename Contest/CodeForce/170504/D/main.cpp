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
#define MOD 1000000007
#define MAX 100005
string str;
int main() {
    cin >> str;
    int n = str.size();
    vector<int> dp(n+10, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        dp[i] = (2*dp[i-1]+1)%MOD;
    }
    int res = 0;
    int cntA = 0;
    for (int i=0; i<n; i++) {
        if (str[i] == 'a') cntA++;
        else if (str[i] == 'b') {
            res = (res + dp[cntA])%MOD;
        }
    }
    printf("%d\n",res);
    return 0;
}
