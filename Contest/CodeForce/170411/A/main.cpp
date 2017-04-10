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
typedef int ll;
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
ll n, k, l, r, b, m;

ll a[1000];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for (int j=1; j<1000; j++) {
        if ((m+j<=n && a[m+j] <= k && a[m+j] > 0) || (m-j>=1 && a[m-j] <= k && a[m-j] > 0)) {
            printf("%d\n",10*j);
            return 0;
        }
    }


    return 0;
}
