#include <iostream>
#include <cstring>
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
int n, x1, y1, x2, y2;
int x[LEN], y[LEN], vx[LEN], vy[LEN];

int main() {
    scanf("%d%d%d%d%d", &n,&x1,&y1,&x2,&y2);
    double ttMin = -1, ttMax = INF;
    rep(i,0,n) scanf("%d%d%d%d", &x[i], &y[i], &vx[i], &vy[i]);
    rep(i,0,n) {
        db xt1, xt2, yt1, yt2;
        if (vx[i] == 0) {
            if (x[i] > x1) xt1 = 0;
            else xt1 = INF;
            if (x[i] < x2) xt2 = INF;
            else xt2 = 0;
        } else if (vx[i] > 0) {
            xt1 = ((double)x1 - (double)x[i])/(double)vx[i];
            xt2 = ((double)x2 - (double)x[i])/(double)vx[i];
        } else {
            xt2 = ((double)x1 - (double)x[i])/(double)vx[i];
            xt1 = ((double)x2 - (double)x[i])/(double)vx[i];
        }
        if (vy[i] == 0) {
            if (y[i] > y1) yt1 = 0;
            else yt1 = INF;
            if (y[i] < y2) yt2 = INF;
            else yt2 = 0;
        } else if (vy[i] > 0) {
            yt1 = ((double)y1 - (double)y[i])/(double)vy[i];
            yt2 = ((double)y2 - (double)y[i])/(double)vy[i];
        } else {
            yt2 = ((double)y1 - (double)y[i])/(double)vy[i];
            yt1 = ((double)y2 - (double)y[i])/(double)vy[i];
        }
        double tMin = max<double>(xt1, yt1), tMax = min<double>(xt2, yt2);
        ttMin = max<double>(ttMin, tMin), ttMax = min<double>(ttMax,tMax);
        ttMin = max<double>(ttMin,0.0);
        if (ttMin >= ttMax) {
            cout << -1 << endl;
            return 0;
        }
    }
    printf("%.20lf\n", ttMin*1.00000001);
    return 0;
}
