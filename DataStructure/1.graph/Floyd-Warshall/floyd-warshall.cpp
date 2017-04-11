#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 99999999
#define pb push_back
#define mp make_pair

// from부터 to까지 (둘다 포함) path에 넣는다.
// NOTE
// 경로가 없는 from->to도 출력한다.
void reconstruct(int from, int to, vector<vector<int> >& via, vector<int> & path) {
    if (via[from][to] == INF) {
        path.pb(from);
        if (from != to) // 겹치는지 확인
            path.pb(to);
    } else {
        int pass = via[from][to];
        reconstruct(from, pass, via, path);
        path.pop_back();
        reconstruct(pass, to, via, path);
    }
}

int main() {

    int v, e;
    cin >> v >> e;
    // floyd-warshall array
    vector<vector<int> > fw(v, vector<int>(v, INF));
    vector<vector<int> > via(v, vector<int>(v, INF));
    for (int i=0; i<v; i++)
        fw[i][i] = 0;
    // get edges
    for (int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        fw[a][b] = min<int>(fw[a][b],w);
    }
    // build
    for (int pass=0; pass<v; pass++) {
        for (int from=0; from<v; from++) {
            for (int to=0; to<v; to++) {
                if (fw[from][to] > fw[from][pass] + fw[pass][to]) {
                    fw[from][to] = fw[from][pass] + fw[pass][to];
                    via[from][to] = pass;
                }
            }
        }
    }
    cout << "Number of path :";
    int n;
    cin >> n;
    while(n--) {
        int f, t;
        cin >> f >> t;
        cout << fw[f][t] << endl;
        vector<int> path;
        reconstruct (f, t, via, path);
        for (int i=0; i<path.size(); i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    return 0;
}
