#include <iostream>
#include <cstring>
#include <istream>
#include <sstream>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
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
#define INF 987654321
#define double long double // use long double when using bisection

int t;


#define LEN 20005
#define INF 987654321

// capacity, flow
vector<pair<int, int> > c[LEN];
map<pair<int,int>, int> cHash, f;
int W, H, B, v;

// Ford-Fulkerson algorithm to calculate maxFlow
int maxFlow (int s, int t) {
    int totalFlow = 0;
    while(true) {
        // implement bfs from source to target
        queue<int> q;
        vector<bool> visit(v, false);
        vector<int> parent(v, -1);
        parent[s] = s;
        q.push(s);
        visit[s] = true;
        while(!q.empty() && !visit[t]) {
            int here = q.front(); q.pop();
            for (int i=0; i<c[here].size(); i++) {
                int there = c[here][i].first;
                int capacity = c[here][i].second;
                if (!visit[there] && capacity - f[make_pair(here,there)] > 0) {
                    parent[there] = here;
                    visit[there] = true;
                    q.push(there);
                }
            }
        }
        if (!visit[t]) break;
        // follow path to get minFlow
        int minFlow = INF;
        for(int here =t; here!= s; here = parent[here]) {
            minFlow = min<int>(minFlow, cHash[make_pair(parent[here],here)]-f[make_pair(parent[here],here)]);
        }
        // update
        totalFlow += minFlow;
        for(int here =t; here!= s; here = parent[here]) {
            f[make_pair(parent[here],here)] += minFlow;
            f[make_pair(here,parent[here])] -= minFlow; // IMPORTANT 유랑의 대칭성
        }
    }
    return totalFlow;
}

int getFrom(int i, int j) {
    return 2*W*i + 2*j + 1;
}
int getTo(int i, int j) {
    return getFrom(i,j)+1;
}
void add(int a, int b, int w) {
        c[a].push_back(make_pair(b,w));
        cHash[make_pair(a,b)] = w;
}

void solve() {
    cin >> W >> H >> B;
    vector<vector<bool> > cell(H, vector<bool> (W, true));
    for (int i=0; i<B; i++) {
        int X0, Y0, X1, Y1;
        cin >> X0 >> Y0 >> X1 >> Y1;
        for (int row=min(Y0,Y1); row<=max(Y0,Y1); row++) {
            for (int col=min(X0,X1); col<=max(X0,X1); col++) {
                cell[row][col] = false;
            }
        }
    }

    int source = 0, sink = 2*W*H+1;
    v = sink+1;
	for (int i=0; i<v; i++) c[i].clear();
	cHash.clear();
	f.clear();

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (!cell[i][j]) continue;
            add(getFrom(i,j), getTo(i,j), 1);
            if (j > 0)
                add(getTo(i,j), getFrom(i,j-1), 1);
            if (j < W-1)
                add(getTo(i,j), getFrom(i,j+1), 1);
            if (i < H-1)
                add(getTo(i,j), getFrom(i+1,j), 1);
        }
    }
    for (int i=0; i<W; i++) {
        add(source, getFrom(0,i),  1);
        add(getTo(H-1,i), sink,  1);
    }

    int res = maxFlow(source, sink);
    cout << res << endl;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
