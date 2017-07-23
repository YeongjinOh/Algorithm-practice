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

int n, a, b;

int main() {
    int cnt = 0;
    scanf("%d%d%d", &n, &a, &b);
    while (n--) {
        int k;
        scanf("%d", &k);
        if (k == 1) {
            if (a > 0) {
                a--;
            } else if (b > 0) {
                b--;
                a++;
            } else {
                cnt++;
            }
        } else {
            if (b > 0) {
                b--;
            } else {
                cnt++;
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
