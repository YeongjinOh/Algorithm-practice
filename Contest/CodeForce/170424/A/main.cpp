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
int a[100005];
int main() {
    scanf("%d%d", &n, &k);
    rep(i,0,n) scanf("%d", &a[i]);
    int minIdx = 0;
    rep(i,1,n) if (a[i] < a[minIdx]) minIdx = i;
    ll cnt = 0;
    rep(i,0,n) {
        if (i != minIdx) {
            ll diff = a[i] - a[minIdx];
            if (diff%k != 0) {
                cout << -1 << endl;
                return 0;
            }
            cnt += diff/k;
        }
    }
    cout << cnt << endl;
    return 0;
}
