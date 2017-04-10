/////////////////////////////////////////////////
//
// build scc(strongly connected components)
//
/////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

vector<vector<int> > adj;
vector<int> visit, sccId;
vector<bool> finish;
int n, m, visitCnt = 1, sccCnt=1;
stack<int> st;


// here를 root로 하는 subtree에서 역방향 간선과 교차간선의 minimal visit을 return
// 이미 SCC에 속한 정점으로 가는 교차간선은 무시!
int scc(int here) {
    int ret = visit[here] = visitCnt++;
    st.push(here);
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];

        // 트리 간선
        if (!visit[there]) {
            ret = min<int>(ret, scc(there));
        } else if (visit[there] < visit[here]) {
            // 교차간선
            if (finish[there]) {
                if (!sccId[there])
                    ret = min<int>(ret, visit[there]);
            // 역방향 간선
            } else {
                ret = min<int>(ret, visit[there]);
            }
        }
    }
    if (ret == visit[here]) {
        while(true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCnt;
            if (t == here) break;
        }
        sccCnt++;
    }

    finish[here] = true;
    return ret;
}

void tarjanSCC() {
    finish = vector<bool>(n,false);
    sccId = visit = vector<int>(n,0);
    for (int here=0; here<n; ++here)
        if (!visit[here])
            scc(here);
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int> >(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    tarjanSCC();

    // print ssc id
    for (int i=0; i<n; i++)
        printf("%d ", sccId[i]);
    cout<<endl;
}
