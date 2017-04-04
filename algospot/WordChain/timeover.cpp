//////////////////////////////////////////////////////////////////////
//
//  This solution solves Hamiltonian path problem which takes O(n!)
//  Thus, it's time over
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C, n;
string str[100];
bool g[100][100];
bool visit[100];
bool done;

void dfs(int here, vector<int> & path) {
    if (done) return;
    path.push_back(here);
    visit[here] = true;
    if (path.size() == n) {
        done = true;
        for (int i=0; i<n; ++i)
            cout << str[path[i]] << " ";
        cout << endl;
    }
    for (int there=0; there<n; there++) {
        if (g[here][there] && !visit[there]) {
            dfs(there,path);
        }
    }
    visit[here] = false;
    path.pop_back();
}


int main() {
    cin >> C;
    while (C--) {
        // reset
        memset(g,0,sizeof(g));
        for (int i=0; i<100; i++) visit[i] = false;
        done = false;

        cin >> n;
        for (int i=0; i<n; i++)
            cin >> str[i];
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (str[i][str[i].size()-1] == str[j][0])
                    g[i][j] = true;
            }
        }
        for (int i=0; i<n; i++) {
            vector<int> path;
            dfs(i, path);
        }
        if (!done)
            cout << "IMPOSSIBLE" << endl;
    }
}
