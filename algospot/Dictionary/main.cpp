#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C;
string str[1005];
vector<int> g[30];
bool visit[30];
vector<int> sol;
bool isCyclic;

void dfs(int here, long long path) {
//    printf("here:%d path:%lld\n",here,path);
    visit[here]=true;
    for (int i=0; i<g[here].size(); ++i) {
        int there = g[here][i];
        if (visit[there]) {
            if ((path>>there & 1) == 1)
                isCyclic = true;
            continue;
        }
        dfs(there, path + (1ll<<there));
    }
    sol.push_back(here);
}

void solve() {
    // reset
    sol.clear();
    for (int i=0; i<26; i++) {
        g[i].clear();
        visit[i]=false;
    }
    isCyclic=false;

    // get input
    int n;
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> str[i];

    // build graph
    for (int i=1; i<n; ++i) {
        int diffPos = 0;
        while (str[i-1].size() > diffPos && str[i].size() > diffPos && str[i-1][diffPos] == str[i][diffPos]) { diffPos++; }
        if (diffPos < str[i-1].size() && diffPos < str[i].size()) {
            int prev = str[i-1][diffPos]-'a', cur = str[i][diffPos]-'a';
            g[cur].push_back(prev);
        }

    }

    // dfsAll
    for (int i=0; i<26; ++i)
        if (!visit[i])
            dfs(i, 1<<i);

    if (isCyclic)
        cout << "INVALID HYPOTHESIS" << endl;
    else {
        for (int i=0; i<sol.size(); i++)
            printf("%c", 'a'+sol[i]);
        cout << endl;
    }
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
