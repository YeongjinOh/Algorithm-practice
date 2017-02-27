#include <iostream>
#include <cstring>
#include <vector>
#define NEG_INF -987654321
#define LEN 100
#define MAX_W 1000
using namespace std;
int C,N,W;
int v[LEN+1], w[LEN+1];
string s[LEN+1];
int maxw[LEN+1][MAX_W], choice[LEN+1][MAX_W];

// n is index of current item
// m is remaining weight
int get(int n, int m) {
    if (m-v[n] < 0) return NEG_INF;
    int& ret = maxw[n][m];
    if (ret != -1) return ret;
    int max = 0, idxOfMax = -1;
    for (int nextN = n+1; nextN <= N; ++nextN) {
        int cur = get(nextN, m-v[n]);
        if (max < cur) {
            max = cur;
            idxOfMax = nextN;
        }
    }
    ret = max + w[n];
    choice[n][m] = idxOfMax;
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> N >> W;
        for (int i=1; i<=N; ++i)
            cin >> s[i] >> v[i] >> w[i];
        v[0] = 0;
        w[0] = 0;
        memset(maxw,-1,sizeof(maxw));
        memset(choice,-1,sizeof(choice));
        cout << get(0,W);
        int n=0,m=W,tmp;
        int cnt = 0;
        vector<string> res;
        while(choice[n][m] != -1) {
            tmp = m;
            m -= v[n];
            n = choice[n][tmp];
            res.push_back(s[n]);
            cnt++;
        }
        cout << " " << cnt << endl;
        for (int i=0; i<res.size(); ++i)
            cout << res[i] << endl;
    }
}
