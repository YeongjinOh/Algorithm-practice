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
#define INF 5e18
ll n, k, l, r, a, b;

#define MAX 200001
int num[MAX];
int main() {
    scanf("%lld", &n);

    int a, b;
    rep(i, 0, n-1) {
        scanf("%d%d", &a, &b);
        num[a]++;
        num[b]++;
    }
    int res = 0;
    rep(i, 0, n+1)
        res = max(res, num[i]);
    cout << res +1 << endl;

    return 0;
}
