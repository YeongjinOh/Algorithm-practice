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
    if (m < 0) return NEG_INF;
    if (n > N) return 0;
    int& ret = maxw[n][m];
    if (ret != -1) return ret;
    int use = get(n+1,m-v[n]) + w[n], unuse = get(n+1,m);
    if (use > unuse)
        ret = use;
    else
        ret = unuse;
    return ret;
}

void reconstruct (int n, int m, vector<string>& res) {
    if (m < 0) return;
    if (n > N) return;
    int use = get(n+1,m-v[n]) + w[n], unuse = get(n+1,m);
    if (use > unuse) {
        res.push_back(s[n]);
        reconstruct(n+1,m-v[n],res);
        return;
    }
    reconstruct(n+1,m,res);
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

        vector<string> res;
        reconstruct(0,W,res);
        cout << " " << res.size() << endl;
        for (int i=0; i<res.size(); ++i)
            cout << res[i] << endl;
    }
}
