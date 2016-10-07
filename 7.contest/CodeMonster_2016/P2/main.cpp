#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define pii pair<int, int>
#define pip pair<int, pii>

const int MAX = 10010;
const int INF = 123456789;
vector< pip > graph;
vector<pii> a[MAX]; // adjacency list
int n, m, u, v, w, s, t;
int MBP[MAX][MAX];
bool visit[MAX];

class UnionSet {
    public:

        int id[MAX], sz[MAX];

        // constructor
        UnionSet(int n) {
            for (int i = 1; i <= n; ++i)
            {
                id[i] = i;
                sz[i] = 1;
            }
        }

        // find the root of given i
        int root(int i) {
            while(i != id[i])
            {
                id[i] = id[id[i]];
                i = id[i];
            }
            return i;
        }

        // check if p and q have the same root
        int check (int p, int q) {
            return root(p)==root(q);
        }

        void unite(int p, int q) {
            int i = root(p);
            int j = root(q);

            if(sz[i] < sz[j]) {
                id[i] = j;
                sz[j] += sz[i];
            } else {
                id[j] = i;
                sz[i] += sz[j];
            }
        }
};

void Kruskal_MST() {
    UnionSet US(n);
    int j=0;
    for (int i = 0; i < m; ++i) {
        u = graph[i].second.first;
        v = graph[i].second.second;
        w = graph[i].first;
        if( !US.check(u, v) ) {
            US.unite(u, v);
            a[u].push_back(pii(w,v));
            a[v].push_back(pii(w,u));
        }
    }
}
int min(int a, int b) {return a>b?b:a;}
void buildMBP (int source) {
    for (int i=1; i<=n; i++) {
        MBP[source][i] = INF;
        visit[i] = false;
    }
    queue<int> pq;
    pq.push(source);
    visit[source] = true;
    while(!pq.empty()) {
        int v = pq.front();
        pq.pop();
        for (int i=0; i<a[v].size(); i++) {
            int u = a[v][i].second, w = a[v][i].first;
            if (!visit[u]) {
                visit[u] = true;
                pq.push(u);
                MBP[source][u] = min(MBP[source][v], w);
            }
        }
    }
    MBP[source][source] = 0;
};

bool myGreater (const pip a, const pip b) { return a.first > b.first; }
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int T;
    inputFile >> T;

    while(T--) {
        printf("%d\n",T);
        inputFile >> n >> m;
        graph.clear();
        graph.resize(m);

        for (int i = 0; i < m; ++i) {
            inputFile >> u >> v >> w;
            graph[i] = pip( w, pii(u,v));
        }
        sort(graph.begin(), graph.end(), myGreater);	//sort the edges in increasing order of cost
        Kruskal_MST();
        for (int i=1; i<=n; i++) {
            buildMBP(i);
        }
        int Q;
        inputFile >> Q;
        long long sum = 0;
        while(Q--) {
            inputFile >> s >> t;
            sum += MBP[s][t];
        }
        outputFile << sum << endl;
        for (int i=1; i<=n; i++) {
            a[i].clear();
        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
