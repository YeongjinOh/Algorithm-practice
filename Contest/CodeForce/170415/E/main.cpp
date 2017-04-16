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
int n, q, p, k;
int a[100005];
int d[305][100005];
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    scanf("%d", &q);
    for (int k=1; k<=300; k++) {
        for (int p=n; p>=1; p--) {
            if (p + a[p] + k > n)
                d[k][p] = 1;
            else
                d[k][p] = d[k][p + a[p] + k] + 1;
        }
    }
    for (int i=0; i<q; i++) {
        scanf("%d%d",&p ,&k);
        int cnt = 0;
        if (k <= 300) {
            cnt = d[k][p];
            cout << cnt << endl;
            continue;
        }
        while(p <= n) {
            p += a[p] + k;
            cnt++;
        }
        cout << cnt << endl;
    }



    return 0;
}
