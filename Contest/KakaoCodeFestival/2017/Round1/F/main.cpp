#include <vector>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int get(pair<int,int> np, vector<int> &ch1, vector<int> &ch2, map<pair<int, int>, int> &maxpair) {
    int &res = maxpair[np];
    if (res > 0) return res;
    int n1 = np.first, n2 == np.second;
    if (ch1[n1].size() == 0 || ch2[n2].size() == 0) return res=1;
    vector<vector<pair<int,int> > > paircombs;
    // impossible to consider all combinations..
    for (int i=0; i<ch1[n1].size(); i++) {
        for (int j=0; j<ch2[n2].size(); j++) {
            res = max(res, get(make_pair(ch1[n1][i], ch2[n2][j]), ch1, ch2, maxpair));
        }
    }
}

int solution(int n1, vector<vector<int> > g1, int n2, vector<vector<int> > g2) {
    vector<int> graph1[105], graph2[105];
    int answer = 0;
    vector<vector<int> > ch1(n1+1, vector<int>());
    vector<vector<int> > ch2(n2+1, vector<int>());
    for (int i=0; i<g1.size(); i++) {
        graph1[g1[i][0]].push_back(g1[i][1]);
        graph1[g1[i][1]].push_back(g1[i][0]);
    }
    for (int i=0; i<g2.size(); i++) {
        graph2[g2[i][0]].push_back(g2[i][1]);
        graph2[g2[i][1]].push_back(g2[i][0]);
    }
    vector<bool> visit(n1+1, false);
    visit[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int i=0; i<graph1[node].size(); i++) {
            int next = graph1[node][i];
            if (visit[next]) continue;
            visit[next] = true;
            q.push(next);
            ch1[node].push_back(next);
            printf("%d - %d\n", node, next);
        }
    }
    visit = vector<bool> (n2+1, false);
    visit[1] = true;
    q.push(1);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int i=0; i<graph2[node].size(); i++) {
            int next = graph2[node][i];
            if (visit[next]) continue;
            visit[next] = true;
            q.push(next);
            ch2[node].push_back(next);
        }
    }
    map<pair<int,int>, int> maxpair;

    return get(1, visit, maxpair);
}

int main() {
    int n1, n2;
    vector<vector<int> > g1, g2;
    cin >> n1;
    for (int i=0; i<n1-1; i++) {
        vector<int> tmp(2); cin >> tmp[0] >> tmp[1];
        g1.push_back(tmp);
    }
    cin >> n2;
    for (int i=0; i<n2-1; i++) {
        vector<int> tmp(2); cin >> tmp[0] >> tmp[1];
        g2.push_back(tmp);
    }
    cout << solution(n1, g1, n2, g2) << endl;
    return 0;
}
