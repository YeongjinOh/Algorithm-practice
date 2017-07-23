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

int n, m;
bool wb[101][101];
int main() {
    scanf("%d%d", &n, &m);
    int l = -1, r = -1, t = -1, b = -1, cnt = 0;;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        for (int j=0; j<m; j++) {
            char c = str[j];
            wb[i][j] = (c == 'B');
            if (c == 'B') {
                cnt++;
                if (l == -1 || j < l) l = j;
                if (r == -1 || j > r) r = j;
                if (t == -1 || i < t) t = i;
                if (b == -1 || i > b) b = i;
            }
        }
    }
    if (cnt == 0) {
        printf("1\n");
        return 0;
    }
    int w = r-l+1, h = b-t+1;
    if (w > n || h > m) {
        printf("-1\n");
        return 0;
    }
    int len = w>h?w:h;
    printf("%d\n", (len*len)-cnt);
    return 0;
}
