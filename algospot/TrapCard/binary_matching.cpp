#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C;
string t[25];
int tId[25][25];
int Agroup[405], Bgroup[405];
bool visit[405];

vector<vector<int> > g;

// binary match
bool dfs(int here) {
    if (visit[here]) return false;
    visit[here] = true;
    for (int i=0; i<g[here].size(); i++) {
        int there = g[here][i];
        if (Bgroup[there] == -1 || dfs(Bgroup[there])) {
            Agroup[here] = there;
            Bgroup[there] = here;
            return true;
        }
    }
    return false;
}

void dfsVisit (int Athere, vector<bool>& chosen) {
    if (chosen[Athere]) {
        chosen[Athere] = false;
        int Bthere = Agroup[Athere];
        if (!chosen[Bthere]) {
            chosen[Bthere] = true;
            dfsVisit(Bgroup[Bthere], chosen);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    memset(tId, -1, sizeof(tId));
    int id = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if(t[i][j] == '.') tId[i][j] = id++;
    g = vector<vector<int> >(id);
    vector<int> A, B;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (tId[i][j] >= 0) {
                if ((i+j)%2 == 0)
                    A.push_back(tId[i][j]);
                else
                    B.push_back(tId[i][j]);
                if (tId[i+1][j] >= 0) {
                    g[tId[i][j]].push_back(tId[i+1][j]);
                    g[tId[i+1][j]].push_back(tId[i][j]);
                }
                if (tId[i][j+1] >= 0) {
                    g[tId[i][j]].push_back(tId[i][j+1]);
                    g[tId[i][j+1]].push_back(tId[i][j]);
                }
            }
        }
    memset(Agroup, -1, sizeof(Agroup));
    memset(Bgroup, -1, sizeof(Bgroup));
    int size = 0;
    for (int i=0; i<A.size(); i++) {
        memset(visit,false,sizeof(visit));
        if (dfs(A[i])) size++;
    }
    vector<bool> chosen(id, true);
    // un choose selected B
    for (int i=0; i<B.size(); i++) if (Bgroup[B[i]] >= 0) chosen[B[i]] = false;
    for (int i=0; i<B.size(); i++) {
        // for element b in B-M
        if (Bgroup[B[i]] == -1) {
            for (int j=0; j<g[B[i]].size(); j++) {
                int Athere = g[B[i]][j];
                if (Agroup[Athere] >= 0)
                    dfsVisit(Athere, chosen);
            }
        }
    }
    printf("%d\n", A.size()+B.size()-size);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (tId[i][j] >= 0 && chosen[tId[i][j]])
                t[i][j] = '^';
            printf("%c",t[i][j]);
        }
        cout << endl;
    }
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
