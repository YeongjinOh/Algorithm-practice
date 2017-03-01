#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 16
#define INF 987654321
using namespace std;
int C, n;
string strs[LEN];
int cache[1<<LEN][LEN];
int benefit[LEN][LEN];

int get(int visit, int prev) {
    if (visit == (1<<(n+1))-1) return 0;

    int &ret = cache[visit][prev];
    if (ret != -1) return ret;
    int cur, idx;
    for (int i=1; i<=n; ++i) {
        if (visit & 1<<i) continue;
        cur = benefit[prev][i] + get(visit + (1<<i), i);
        if (ret < cur) {
            ret = cur;
        }
    }
    return ret;
}
void print(int visit, int prev) {
    if (visit == (1<<(n+1))-1) return;
    int cur;
    for (cur=1; cur<=n; cur++) {
        if (visit & 1<<cur) continue;
        if (benefit[prev][cur] + get(visit + (1<<cur), cur) == get(visit,prev))
            break;
    }
    cout << strs[cur].substr(benefit[prev][cur]);
    print(visit + (1<<cur), cur);
}

int main() {
    cin >> C;
    strs[0] = "";
    while (C--) {
        cin >> n;
        for (int i=1; i<=n; ++i)
            cin >> strs[i];

        // build benefits from each pair
        memset(benefit,-1,sizeof(benefit));
        for (int i=1; i<=n; ++i) {
            benefit[0][i] = 0;
            benefit[i][0] = 0;
            for (int j=1; j<=n; ++j) {
                if (i == j) continue;
                benefit[i][j] = 0;
                for (int s=0; s<strs[i].length(); ++s) {
                    int len = 0;
                    while(s+len < strs[i].length() && len < strs[j].length() && strs[i][s+len] == strs[j][len]) {len++;}
                    if (s+len == strs[i].length()) {
                        benefit[i][j] = len;
                        break;
                    }
                    ///////////////////////////////
                    // this part is nessacary!
                    // if included, remove
                    if (len == strs[j].length() ) {
                        strs[j] = "";
                        for (int k=1; k<=n; ++k) {
                            benefit[j][k] = 0;
                            benefit[k][j] = 0;
                        }
                        break;
                    }
                }
            }
        }

        // build cache
        memset(cache,-1,sizeof(cache));
        get(1,0);
        print(1,0);
        cout << endl;
    }
}
