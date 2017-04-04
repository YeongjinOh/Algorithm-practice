/////////////////////////////////////////////////
//
// find cut vertex (p. 854)
//
/////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > adj;
vector<int> visit, cutVertex;
int n, m, cnt = 1;

// find cut vertex
// return minimal visit of ancestor
int findCutVertex (int here, bool isRoot=false) {
    visit[here] = cnt++;
    int ret = visit[here];
    int children = 0;
    bool isHereCutVertex = false;
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        if (!visit[there]) {
            int cur = findCutVertex(there);
            ret = min<int>(ret, cur);
            children++;
            if (!isRoot && cur >= visit[here])
                isHereCutVertex = true;
        } else {
            ret = min<int>(ret, visit[there]);
        }
    }
    if (isRoot && (children >= 2))
        isHereCutVertex = true;
    if  (isHereCutVertex)
        cutVertex.push_back(here);
    return ret;
}

void dfsAll() {
    visit = vector<int>(n,0);
    for (int i=0; i<n; i++)
        if (!visit[i])
            findCutVertex(i,true);
}


int main() {
    cin >> n >> m;
    adj = vector<vector<int> >(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsAll();

    // print all cut vertices
    for (int i=0; i<cutVertex.size(); i++)
        printf("%d ", cutVertex[i]);
    cout << endl;
}
