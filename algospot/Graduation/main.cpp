#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_N 12
#define MAX_M 10
#define INF 987654321

using namespace std;
int C, N, K, M, L;

// pre[i] : i-th 교과목의 선수 교과목 bitmask
// sem[i] : i 번째 학기에 열리는 교과목들
int pre[MAX_N], sem[MAX_M];
int cache[1<<MAX_N][MAX_M];

int bitCount (int n) {
    if (n == 0) return 0;
    return n%2 + bitCount(n >> 1);
}
// cur : current status
// numSem : number of semester passed
int search(int cur, int numSem) {
    if (bitCount(cur) >= K) return 0;
    if (numSem >= M) return INF;
    int &ret = cache[cur][numSem];
    if (ret != -1) return ret;

    int possible = 0;
    for (int i=0; i<N; ++i) {
        // already taken
        if (cur & 1<<i) continue;
        // not open for this semester
        if ((sem[numSem] & (1<<i)) == 0) continue;
        // didn't take all pre-requisites
        if (pre[i] & ~cur) continue;
        possible |= 1 << i;
    }

    ////////////////////////////////////////////////////////////
    // important
    // how to explore all subsets
    // nextSubset = (currentSubset-1) & entireSet
    ////////////////////////////////////////////////////////////
    ret = INF;
    for (int subset = possible; subset >0; subset = (subset-1)&possible) {
        if (bitCount(subset) > L) continue;
        ret = min<int>(ret, search(cur|subset, numSem+1)+1);
    }
    ret = min<int>(ret, search(cur, numSem+1));
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> N >> K >> M >> L;

        // get pri
        memset(pre,0,sizeof(pre));
        for (int i=0; i<N; i++)  {
            int r, bm = 0;
            cin >> r;
            for (int j=0; j<r; ++j) {
                // i-th 교과목의 선수교과목 번호
                int p;
                cin >> p;
                bm |= 1<<p;
            }
            pre[i] = bm;
        }

        // get semester information
        memset(sem,0,sizeof(sem));
        for (int i=0; i<M; ++i) {
            int c, bm = 0;
            cin >> c;
            for (int j=0; j<c; ++j) {
                int s;
                cin >> s;
                bm |= 1<<s;
            }
            sem[i] = bm;
        }

        memset(cache,-1,sizeof(cache));
        int ret = search(0, 0);
        if (ret >= INF) cout << "IMPOSSIBLE" << endl;
        else cout << ret << endl;
    }
}
