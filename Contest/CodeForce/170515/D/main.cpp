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
int n;
int a[LEN];
long long sum[LEN];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    sum[0] = 0;
    for (int i=1; i<=n; i++)
        sum[i] = sum[i-1] + a[i-1];
    map<ll, int> hs;
    for (int k=1; k<n; k++) {
        ll diff = sum[n]-2*sum[k];
        if (diff == 0) {
            cout << "YES" << endl;
            return 0;
        }
        hs[diff] = k;
    }
    for (int i=0; i<n; i++) {
        int curA = a[i];
        int k1 = hs[-2*curA], k2 = hs[2*curA];
        if ( (i < k1 && sum[n] - 2*sum[k1] == -2*curA) || (i>=k2 && sum[n] - 2*sum[k2] == 2*curA) ) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
