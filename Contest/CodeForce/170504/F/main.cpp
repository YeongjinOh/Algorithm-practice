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
#define LEN 100005
struct DisjointSet {
	vector<int> parent, rk;
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
int dist[2][LEN];
vector<vector<int> > g;
vector<int> dia;
vector<int> hsMaxDia;
vector<vector<long long> > compDia; // component diameters
vector<vector<long long> > compSum;
// idx means dist[idx]
int far (int v, int idx) {
	queue<int> q;
	vector<bool> visit(n+1,false);
	visit[v] = true;
	q.push(v);
	int d = 0;
	int last = v;
	while (!q.empty()) {
		for (int i=0, n=q.size(); i<n; i++) {
			int u = q.front();
			q.pop();
			last = u;
			dist[idx][u] = d;
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
	return last;
}

double calc (int pa, int pb) {
	ll diaSum = 0, cnt = 0;
	ll maxDia = max<int>(hsMaxDia[pa], hsMaxDia[pb]);
	ll sizeA = compDia[pa].size(), sizeB = compDia[pb].size();
    //////////////////////////////////////////////////////////
    // IMPORTANT
    // really important optimization
    //////////////////////////////////////////////////////////
    if (sizeA > sizeB) return calc(pb, pa);
	for (int i=0; i<sizeA; i++) {
		ll curDia = compDia[pa][i];
		vector<ll>::iterator it = lower_bound(compDia[pb].begin(), compDia[pb].end(), maxDia-1-curDia);
		ll numOfBelow = it-compDia[pb].begin();
		diaSum += (ll)maxDia * numOfBelow;
		diaSum += (compSum[pb].back() - compSum[pb][numOfBelow]);
        diaSum += (ll)(curDia + 1) * (sizeB - numOfBelow);
	}
	double avg = (double)diaSum / (double)(sizeA * sizeB);
	return avg;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	DisjointSet ds(n);
	g = vector<vector<int> >(n+1);
	dia = vector<int>(n+1, 0);
	hsMaxDia = vector<int>(n+1,0);
	compDia = vector<vector<long long> >(n+1); // component diameters
	compSum = vector<vector<long long> >(n+1);
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
		ds.merge(a,b);
	}
    /////////////////////////////////////////////////////////////
    // IMPORTANT
    //
    // find all pair diameters O(n)
	/////////////////////////////////////////////////////////////
	for (int v=1; v<=n; v++) {
		if (ds.find(v) == v) {
			// 1. find longest path (v,u) from v
			// 2. find longest path (u,z) from u
			// maximal diameter is max(dia(v,u),(v,z)) for every z
			int u = far(v,0);
			int z = far(u,0);
			far(z,1);
		}
	}
	for (int v=1; v<=n; v++) {
		dia[v] = max(dist[0][v], dist[1][v]); // maximal diameter at v
		int pv = ds.find(v);
		hsMaxDia[pv] = max<int>(hsMaxDia[pv], dia[v]); // update group's maximal diameter
		compDia[pv].push_back(dia[v]);
	}
	for (int v=1; v<=n; v++) {
		sort(compDia[v].begin(), compDia[v].end());
        compSum[v].resize(compDia[v].size()+1);
		compSum[v][0] = 0;
		for (int j=0; j<compSum[v].size()-1; j++) {
			compSum[v][j+1] = compSum[v][j] + compDia[v][j];
		}
	}
	map<pii, double> hs;
	int sizeThres = 300;
	vector<int> P; // list of parents
	for (int v=1; v<=n; v++)
		if (ds.find(v) == v && compDia[ds.find(v)].size() >= sizeThres) P.pb(v);
	for (int i=0; i<P.size(); i++) {
		for (int j=0; j<i; j++) {
			int pa = P[i], pb = P[j];
			double avg = calc(pa,pb); // pb < pa
			hs[pii(pa,pb)] = avg;
		}
	}
	for (int i=0; i<q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int pa = ds.find(a), pb = ds.find(b);
		if (pa < pb) swap(pa, pb); // pa > pb
	    int sizeA = compDia[pa].size(), sizeB = compDia[pb].size();
		if (pa == pb) {
			printf("-1\n");
		} else if (sizeA >= sizeThres && sizeB >= sizeThres) {
			printf("%.8lf\n", hs[mp(pa,pb)]);
		} else {
			double avg = calc(pa, pb);
			printf("%.8lf\n", avg);
		}
	}
	return 0;
}
