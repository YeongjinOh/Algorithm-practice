#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 10
#define vi vector<int>

vi adj[MAX];
vector<int> discovered, finished;
int cnt = 1;
int n, m;
vector<pair<int, int> > treeedge, forwardedge, backedge, crossedge;
void dfs (int here) {
    cout << "visit " << here << endl;
    discovered[here] = cnt++;
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        pair<int,int> e = make_pair(here,there);

        // tree edge
        if (!discovered[there]) {
            treeedge.push_back(e);
            dfs(there);

        // forward edge
        } else if (discovered[here] < discovered[there]) {
            forwardedge.push_back(e);

        // cross edge
        } else if (finished[there]) {
            crossedge.push_back(e);

        // backward edge
        } else {
            backedge.push_back(e);
        }

    }

    finished[here] = 1;
}

void dfsAll() {
    discovered = vector<int>(n,0);
    finished = vector<int>(n,0);
    for (int i=0; i<n; i++)
        if (!discovered[i])
            dfs(i);
}

void printEdgeInfo() {
    cout << " - tree edges - " << endl;
    for (int i=0; i<treeedge.size(); i++) printf("(%d,%d)\n",treeedge[i].first, treeedge[i].second);

    cout << " - forward edges - " << endl;
    for (int i=0; i<forwardedge.size(); i++) printf("(%d,%d)\n",forwardedge[i].first, forwardedge[i].second);

    cout << " - backward edges - " << endl;
    for (int i=0; i<backedge.size(); i++) printf("(%d,%d)\n",backedge[i].first, backedge[i].second);

    cout << " - cross edges - " << endl;
    for (int i=0; i<crossedge.size(); i++) printf("(%d,%d)\n",crossedge[i].first, crossedge[i].second);
}


int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        // directed graph
        adj[a].push_back(b);
    }
    dfsAll();
    printEdgeInfo();
}
