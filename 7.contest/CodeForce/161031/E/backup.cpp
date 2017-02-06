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
ll n, k, l, r, res, a, b;


int main() {
    char str[1000010];
    bool up;
    scanf("%lld%s", &n, str);
    for (int i=0; i<n; i++) {
        res = 0;
        l = i;
        r = i;
        up =  (str[i] == 'U');
        while(true) {
            if (res > 2000000) {
                printf("-1 ");
                break;
            }
            if (up) {
                r++;
                while(r<n && str[r] == 'U') {
                    r++;
                }
                res += r-l;
                if (r == n) {
                    printf("%lld ", res);
                    break;
                }
                up = !up;
            } else {
                l--;
                while(l>=0 && str[l] == 'D') {
                    l--;
                }
                res += r-l;
                if (l < 0) {
                    printf("%lld ", res);
                    break;
                }
                up = !up;
            }
        }
    }
    return 0;
}
