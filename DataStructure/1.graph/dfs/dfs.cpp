#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

#define MAX 10
#define vi vector<int>

vi adj[MAX];
vector<bool> visit;
int n, m;

void dfs (int here) {
    printf("%d ", here);
    visit[here] = true;
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        if (!visit[there])
            dfs(there);
    }
}

void dfsIterative (int here) {
    // stack (here, i)
    stack<pair<int, int> > st;
    st.push(make_pair(here, 0));
    while (!st.empty()) {
        int cur = st.top().first;
        int start = st.top().second;
        st.pop();
        if (start == 0) {
            visit[cur] = true;
            printf("%d ", cur);
        }
        for (int i = start; i <adj[cur].size(); ++i) {
            int there = adj[cur][i];
            if (!visit[there]) {
                st.push(make_pair(cur, i+1));
                st.push(make_pair(there, 0));
                break;
            }
        }
    }
}

void dfsAll() {
    visit = vector<bool>(n, false);
    printf("dfsAll \t\t: ");
    for (int i=0; i<n; i++)
        if (!visit[i])
            dfs(i);
    printf("\n");
}

void dfsAllIterative() {
    visit = vector<bool>(n, false);
    printf("dfsAllIterative : ");
    for (int i=0; i<n; i++)
        if (!visit[i])
            dfsIterative(i);
    printf("\n");
}


int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsAll();
    dfsAllIterative();

}
