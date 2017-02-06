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
ll n, k, l, r;
ll a[100010], b[100010], c[100010];
ll maxll (ll a, ll b) { return a>b?a:b;}
ll minll (ll a, ll b) { return a<b?a:b;}

int main() {
    scanf("%lld", &n);
    ll maxidx;
    r=0;
    ll aa,bb,cc, tmp;
    for (int i=1; i<=n; i++) {
        scanf("%lld%lld%lld", &aa, &bb, &cc);
        if (aa < bb) {
            tmp = aa;
            aa = bb;
            bb = tmp;
        }
        if (bb < cc) {
            tmp = cc;
            cc = bb;
            bb = tmp;
        }
        if (aa < bb) {
            tmp = aa;
            aa = bb;
            bb = tmp;
        }
        a[i] = aa;
        b[i] = bb;
        c[i] = cc;
        if (r < c[i]) {
            r = c[i];
            maxidx = i;
        }
    }
    k=1;
    //left answer, right answer
    int la=0, ra=0;
    for (int i=1; i<=n; i++) {
        if (b[i] < r)
            continue;
        for (int j=i+1; j<=n; j++) {
            if (b[j] < r)
                continue;
            // 조합 가능한지 찾기
            if (a[i] == a[j]) {
                if (b[i] == b[j]) {
                    if (c[i] + c[j] > r) {
                        r = minll(b[i], c[i]+c[j]);
                        la = i;
                        ra = j;
                    }
                    // else continue;
                } else if (b[i] > b[j]) {
                    if (c[i] == b[j]) {
                        r = b[j];
                        la = i;
                        ra = j;
                    }
                    // else continue;
                } else {
                    if (c[j] == b[i]) {
                        r = b[i];
                        la = i;
                        ra = j;
                    }
                }
            }
        }
    }
    if (la == 0)
        printf("1\n%lld\n", maxidx);
    else
        printf("2\n%d %d\n",la,ra);

    return 0;
}
