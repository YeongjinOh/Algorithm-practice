#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
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

struct DisjointSet {
    vector<int> parent;
    DisjointSet (int n) : parent(n+1) {
        for (int i=0; i<=n; i++)
            parent[i]=i;
    }
    int find (int here) {
        if (parent[here] == here)
            return here;
        return parent[here] = find(parent[here]);
    }
    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        parent[pa] = pb;
    }
};


int n, m, q;

int main() {
    scanf("%d%d%d", &n, &m, &q);
    vector<vector<int> > g(n+1);
    DisjointSet ds(n);
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        ds.merge(a,b);
    }
    vector<int> dia(n+1, 0);
    map<int, int> hsMaxDia;
    // build set
    vector<vector<int> > compDia(n+1); // component diameters

    // build diameters at each vertex
    // O(n^2)
    // should be improved
    for (int v=1; v<=n; v++) {
        queue<int> q;
        vector<bool> visit(n+1,false);
        visit[v] = true;
        q.push(v);
        int d = 0;
        while (!q.empty()) {
            for (int i=0, n=q.size(); i<n; i++) {
                int u = q.front();
                q.pop();
                for (int i=0; i<g[u].size(); i++) {
                    int next = g[u][i];
                    if (!visit[next]) {
                        q.push(next);
                        visit[next] = true;
                    }
                }
            }
            d++;
        }
        dia[v] = d-1;
        int pv = ds.find(v);
        hsMaxDia[pv] = max<int>(hsMaxDia[pv], d-1);
        compDia[pv].push_back(d-1);
    }
    for (int v=1; v<=n; v++) {
        sort(compDia[v].begin(), compDia[v].end());
    }
    vector<vector<int> > compSum = compDia;
    for (int v=1; v<=n; v++) {
        compSum[v].push_back(0);
        sort(compSum[v].begin(), compSum[v].end());
        for (int j=0; j<compSum[v].size()-1; j++) {
            compSum[v][j+1] += compSum[v][j];
        }
    }
    map<pii, double> hs;
    for (int i=0; i<q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int pa = ds.find(a), pb = ds.find(b);
        if (pa < pb) swap(pa, pb); // pa > pb
        if (pa == pb) {
            printf("-1\n");
        } else if (hs.find(mp(pa,pb)) != hs.end()) {
            printf("%.8lf\n", hs[mp(pa,pb)]);
        } else {
            long long diaSum = 0, cnt = 0;
            int maxDia = max<int>(hsMaxDia[pa], hsMaxDia[pb]);
            // calc all pair sum max(maxValue,a+b) (a in A, b in B)
            // O(nlogn)
            int sizeA = compDia[pa].size(), sizeB = compDia[pb].size();
            for (int i=0; i<sizeA; i++) {
                int curDia = compDia[pa][i];
                vector<int>::iterator it = lower_bound(compDia[pb].begin(), compDia[pb].end(), maxDia-1-curDia);
                int numOfBelow = it-compDia[pb].begin();
                diaSum += maxDia * numOfBelow;
                diaSum += (compSum[pb].back() - compSum[pb][numOfBelow]) + (curDia + 1) * (sizeB - numOfBelow);

            }
            double avg = (double)diaSum / (double)(sizeA * sizeB);
            hs[mp(pa,pb)] = avg;
            printf("%.8lf\n", avg);
        }
    }
    return 0;
}
