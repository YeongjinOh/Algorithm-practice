////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// NOTE
//
// DP를 이용한 풀이 방법.
// 동전 쌓기 문제 처럼, diff(t[0][i]-t[1][i])로 가는 (t[0][i]의) 최소값을 -199~199까지 각각 구해논다.
// 정답은에 해당하는 i의 Multiset을 positive와 negative로 나누면 S_pos, S_neg
// 각각의 diff_i(in S_pos)와 diff_i(in S_neg)는 해당 diff로 가는 최소 경로가 된다.
// 즉, positivie와 negative 각각에 대해 동전쌓기처럼 최적해를 구한 뒤 두 합이 0이되는 값들의 최소값을 구한다.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int C;
void solve() {
    int m;
    cin >> m;
    int t[2][500];
    for (int i=0; i<m; i++)
        scanf("%d%d", &t[0][i], &t[1][i]);
    // -200~200
    int diff[401];
    for (int i=0; i<401; i++)
        diff[i] = INF;
    for (int i=0; i<m; i++) {
        int sub = t[0][i] - t[1][i];
        diff[sub+200] = min<int>(diff[sub+200], t[0][i]);
    }
    int maxComb = 40000;
    vector<int> pos(maxComb+1, INF), neg(maxComb+1, INF);
    // build positive
    int ans = INF;
    for (int i=0; i<=maxComb; i++) {
        if (i<=200) {
            pos[i] = diff[200+i];
            neg[i] = diff[200-i];
        }
        for (int j=0; j<=200 && j<=i; j++) {
            pos[i] = min<int>(pos[i],pos[i-j]+diff[200+j]);
            neg[i] = min<int>(neg[i],neg[i-j]+diff[200-j]);
        }
        ans = min<int>(ans, pos[i]+neg[i]);
    }
    if (ans >= INF) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
