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

string str;
int len;

#define LEN 100000
class segtree {
    public:
        int n, k;
        char c;
        vector<int> seg;
        segtree(int n, int k, char c) : n(n), k(k), c(c), seg(4*len, 0) { }

        void build() {
            build(0, len-1, 0);
/*            printf("build c:%c n:%d k:%d\n", c, n, k);
            for (int i=0; i<seg.size(); i++) {
                printf("%d ", seg[i]);
            }
            cout << endl;
*/        }

        // 구간 합
        // 구간 update
        void build(int start, int end, int node) {
            if (start == end) {
                if (start%n == k && str[start] == c) seg[node] = 1;
                return;
            }
            int mid = (start+end)/2;
            build(start, mid, node*2+1);
            build(mid+1, end, node*2+2);
            seg[node] = seg[node*2+1] + seg[node*2+2];
        }

        int query(int start, int end, int node, int l, int r) {
            if (start > r || end < l) return 0;
            if (l <= start && end <= r) return seg[node];
            int mid = (start+end)/2;
            return query(start, mid, node*2+1, l, r) + query(mid+1, end, node*2+2, l, r);
        }

        int update(int start, int end, int node, int l, int r, int diff) {
            if (start > r || end < l)
                return seg[node];
            if (start == end) {
                seg[node] += diff;
                return seg[node];
            }
            int mid = (start+end)/2;
            return seg[node] = update(start, mid, 2*node+1, l, r, diff) + update(mid+1, end, 2*node+2, l, r, diff);
        }

        // idx번째 위치에 c가 있었는데 다른 문자로 바꾸면, idx를 포함하는 범위를 --
        void update(int idx, char cc) {
            if (idx % n != k) return;
            if (str[idx] == c && c != cc)
                update(0, len-1, 0, idx, idx, -1);
            else if (str[idx] != c && c == cc)
                update(0, len-1, 0, idx, idx, 1);
        }
};

int main() {
    cin >> str;
    len = str.size();
    map<char, vector<vector<segtree> > > mseg;
    char chars[] = {'A', 'T', 'G', 'C'};
    for (int i=0; i<4; i++) {
        char c = chars[i];
        vector<vector<segtree> > vseg(10);
        for (int n=1; n<=10; n++) {
            for (int k=0; k<n; k++) {
                segtree seg(n, k, c);
                seg.build();
                vseg[n-1].pb(seg);
            }
        }
        mseg[c] = vseg;
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            char c;
            scanf("%d", &x);
            cin >> c;
            x--;
            if (str[x] == c) continue;
            for (int i=0; i<4; i++) {
                vector<vector<segtree> > &vseg = mseg[chars[i]];
                for (int n=1; n<=10; n++) {
                    for (int k=0; k<n; k++) {
                        vseg[n-1][k].update(x, c);
                    }
                }
            }
            str[x] = c;
        } else {
            int l, r;
            string e;
            scanf("%d%d", &l, &r);
            l--; r--;
            cin >> e;
            int n = e.size();
            int res = 0;
            for (int i=0; i<n; i++) {
                char c = e[i];
                vector<vector<segtree> > &vseg = mseg[c];
                int k = (l+i)%n;
                int cur =  vseg[n-1][k].query(0, len-1, 0, l, r);
                res += cur;
//                printf("c:%c n:%d k:%d cur:%d\n", c, n, k, cur);
            }
            printf("%d\n", res);
        }
    }
}
