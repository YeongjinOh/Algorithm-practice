//////////////////////////////////////////////////////////////////////
//
//  get Euler Circuit of directed graph with all points even degree
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > adj;
vector<bool> visit;
int n, m;

void getEulerCircuit(int here, vector<int> & circuit) {
    for (int there = 0; there < adj.size(); ++there) {
        // number of edges between here and there
        while(adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

void showCircuit (vector<int>& circuit) {
    for (int i=0; i<circuit.size(); i++)
        cout << circuit[i] << " ";
    cout << endl;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int > >(n, vector<int> (n, 0));
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b]++;
    }
    vector<int> circuit;
    getEulerCircuit(0, circuit);
    reverse(circuit.begin(), circuit.end());
    showCircuit(circuit);
    return 0;
}
