#include <iostream>
#include <cstring>
#define MAX_LEN 500
#define INF 987654321
using namespace std;
int C, n, m;
long long A[MAX_LEN], B[MAX_LEN];
int cache[MAX_LEN][MAX_LEN]; // cache for memoization

const long long NEGINF = numeric_limits<long long>::min();

int get(int curA, int curB) {
    int &ret = cache[curA][curB];
    if (ret != -1)
        return ret;
    int max = 0;
    for (int nextA = curA+1; nextA<=n; ++nextA) {
        if (A[curA] < A[nextA] && B[curB] < A[nextA]) {
            int cur = get(nextA, curB);
            if (max < cur) max = cur;
        }
    }
     for (int nextB = curB+1; nextB<=m; ++nextB) {
        if (A[curA] < B[nextB] && B[curB] < B[nextB]) {
            int cur = get(curA, nextB);
            if (max < cur) max = cur;
        }
    }
    ret = 1+max;
    return ret;
}


// TODO change dp from Top-down to Bottom-up
int main() {
    cin >> C;
    while (C--) {
        cin >> n >> m;
        A[0] = NEGINF;
        B[0] = NEGINF;
        for (int i=1; i<=n; ++i)
            cin >> A[i];
        for (int i=1; i<=m; ++i)
            cin >> B[i];

        /* Top-down */
        memset(cache,-1,sizeof(cache));
        cout << get(0,0)-1 << endl;
    }
    return 0;
}
