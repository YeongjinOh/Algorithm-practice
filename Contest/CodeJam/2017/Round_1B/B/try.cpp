#include <iostream>
#include <queue>
#include <vector>
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
#define INF 98754321


// from부터 to까지 (둘다 포함) path에 넣는다.
// NOTE
// 경로가 없는 from->to도 출력한다.
void reconstruct(int from, int to, vector<vector<int> >& via, vector<int> & path) {
    if (via[from][to] == INF) {
        path.pb(from);
        if (from != to) // 겹치는지 확인
            path.pb(to);
    } else {
        int pass = via[from][to];
        reconstruct(from, pass, via, path);
        path.pop_back();
        reconstruct(pass, to, via, path);
    }
}

void connect(vector<int> from, vector<int> to, vector<vector<int> >& e, vector<vector<int> >& fw) {
    for (int i=0; i<from.size(); i++) {
        int a = from[i];
        for (int j=0; j<to.size(); j++) {
            int b = to[j];
            fw[a][b] = min<int>(fw[a][b],-1);
            e[a][b] = 1;
        }
    }
}

void solve () {
    int N, R, O, Y, G, B, V;
    cin >> N >> R >> O >> Y >> G >> B >> V;
    vector<int>  rs, os, ys, gs, bs, vs;
    int id = 0;
    rep(i, 0, R)
        rs.push_back(id++);
    rep(i, 0, O)os.push_back(id++);
    rep(i, 0, Y) ys.push_back(id++);
    rep(i, 0, G) gs.push_back(id++);
    rep(i, 0, B) bs.push_back(id++);
    rep(i, 0, V) vs.push_back(id++);

    // floyd-warshall array
    int v = id;
    vector<vector<int> > e(v, vector<int>(v, 0));
    vector<vector<int> > fw(v, vector<int>(v, INF));
    vector<vector<int> > via(v, vector<int>(v, INF));
    for (int i=0; i<v; i++)
        fw[i][i] = 0;

    // connect edges
    connect(rs, bs, e, fw);
    connect(rs, gs, e, fw);
    connect(rs, ys, e, fw);
    connect(os, bs, e, fw);
    connect(ys, bs, e, fw);
    connect(ys, vs, e, fw);
    connect(ys, rs, e, fw);
    connect(gs, rs, e, fw);
    connect(bs, rs, e, fw);
    connect(bs, os, e, fw);
    connect(bs, ys, e, fw);
    connect(vs, ys, e, fw);

    // build
    for (int pass=0; pass<v; pass++) {
        for (int from=0; from<v; from++) {
            for (int to=0; to<v; to++) {
                if (fw[from][to] > fw[from][pass] + fw[pass][to]) {
                    fw[from][to] = fw[from][pass] + fw[pass][to];
                    via[from][to] = pass;
                }
            }
        }
    }
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            printf("%d ", fw[i][j]);
        }
        cout << endl;
    }
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            if (i!=j && fw[i][j] == 1-v && e[j][i] == 1) {
                vector<int> path;
                reconstruct (i, j, via, path);
                for (int i=0; i<path.size(); i++)
                    printf("%d ", path[i]);
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
