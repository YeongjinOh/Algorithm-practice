//////////////////////////////////////////////////////////////////////
//
//  This solution solves Euler Trail
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C, n;
int g[26][26];
int start;

bool checkEulerCircuitExists () {
    int degreeOut[26], degreeIn[26];
    memset(degreeOut, 0, sizeof(degreeOut));
    memset(degreeIn, 0, sizeof(degreeIn));
    for (int i=0; i<26; i++) {
        for (int j=0; j<26; j++) {
            degreeOut[i] += g[i][j];
            degreeIn[j] += g[i][j];
        }
    }
    int pos = 0, neg = 0;
    for (int i=0; i<26; i++) {
        int diff = degreeOut[i] - degreeIn[i];
        if (diff < -1 || diff > 1) return false;
        if (diff == 1) {
            pos++;
            start = i;
        }
        if (diff == -1) neg++;
    }
    // Euler Trail
    if (pos == 1 && neg == 1) return true;
    // Euler Circuit
    if (pos == 0 && neg == 0) return true;
    return false;
}

///////////////////////////////////////////////////////////////
//
// NOTE
// 방향 그래프이지만, 무향 그래프에서의 EulerCircuit 구하는 것과 유사하다.
// g[there][here]--; 파트만 빠지면 됨.
//
///////////////////////////////////////////////////////////////
void getEulerCircuit (int here, vector<int>& circuit) {
    for (int there=0; there<26; ++there) {
        while(g[here][there] > 0) {
            g[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

int main() {
    cin >> C;
    while (C--) {
        // reset
        memset(g,0,sizeof(g));
        vector<string> gstr[26][26];
        string str[100];

        // read
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> str[i];
        for (int i=0; i<n; i++) {
            int from = str[i][0]-'a', to = str[i][str[i].size()-1]-'a';
            gstr[from][to].push_back(str[i]);
            g[from][to]++;
        }
        start = -1;

        /////////////////////////////////////////////////////////////////
        //  IMPORTANT
        //
        //  Euler Circuit(Trail)을 구하기 전에, 존재 여부는 확인해야 한다.
        //  그러지 않을 경우 segmentation fault!
        //
        /////////////////////////////////////////////////////////////////
        if (!checkEulerCircuitExists()) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<int> circuit;
        /////////////////////////////////////////////////////////////////
        // IMPORTANT
        //
        // Euler Circuit인 경우 아무 점에서나 시작
        // Euler Trail인 경우 시작점을 계산해 주어야 한다!
        //
        // //////////////////////////////////////////////////////////////
        getEulerCircuit(start < 0?str[0][0]-'a':start, circuit);
        reverse(circuit.begin(), circuit.end());
        if (circuit.size() <= n)
            cout << "IMPOSSIBLE" << endl;
        else {
            for (int i=1; i<circuit.size(); i++) {
                int from = circuit[i-1], to = circuit[i];
                if (gstr[from][to].size() > 0) {
                    cout << gstr[from][to].back() << " ";
                    gstr[from][to].pop_back();
                }
            }
            cout << endl;
        }
    }
}
