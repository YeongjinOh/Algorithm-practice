#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_LEN 105
bool table[MAX_LEN][MAX_LEN];

int main() {
    int C, N;
    cin >> C;
    string wild;
    while (C--) {
        cin >> wild >> N;

        // split wildcard
        vector<string> wilds;
        int start = 0;
        for (int i=0; i<wild.size(); ++i) {
            if (wild[i] == '*') {
                wilds.push_back(wild.substr(start,i+1-start));
                start = i+1;
            }
        }
        if (start != wild.size())
            wilds.push_back(wild.substr(start,wild.size()));

        // table size is n+1 by m+1
        int n, m = wilds.size();

       vector<string> sols;
        while (N--) {
            string name;
            cin >> name;
            n = name.size();

            //reset tables
            for (int i=0; i<=n; ++i)
                for (int j=0; j<=m; ++j)
                    table[i][j] = false;
            table[0][0] = true;

            // check
            for (int j=1; j<=m; ++j) {
                string curWild = wilds[j-1];
                if (curWild.size() == 1 && curWild[0] == '*') {
                    bool find = false;
                    for (int i=0; i<=n; ++i) {
                        if (table[i][j-1])
                            find = true;
                        table[i][j] = find;
                    }
                    continue;
                }
                for (int i=1; i<=n; ++i) {
                    if (!table[i-1][j-1] || table[i][j])
                        continue;
                    bool success = true;
                    // one element before last character
                    int s;
                    for (s=0; s<curWild.size()-1; ++s) {
                        if (name[i-1+s] != curWild[s] && curWild[s] != '?')
                            success = false;
                    }
                    // s should be finished at curWild.size()-1
                    // last character
                    if (success) {
                        if (curWild[s] == '*') {
                            for (int k=i; k<=n; ++k) {
                                table[k][j] =  true;
                            }
                        } else if (curWild[s] == name[i-1+s] || curWild[s] == '?') {
                            table[i+s][j] = true;
                        }
                    }
                }
            }
            // show tables
            if (table[n][m])
                sols.push_back(name);
        }
        sort(sols.begin(), sols.end());
        for (int i=0; i<sols.size(); ++i)
            cout << sols[i] << endl;
    }
    return 0;
}
