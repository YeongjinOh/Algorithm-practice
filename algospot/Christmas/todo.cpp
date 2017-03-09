#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100001
#define MOD 20091101
#define INF 987654321
using namespace std;
int C, n, k;
int d[MAX] = {0};
int main() {
    cin >> C;
    while (C--) {
        queue<int> remainders[MAX];
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            scanf("%d",&d[i]);
            d[i] += d[i-1];
            // 이 부분 때문에 RunTime error
            // why??
//            remainders[d[i]%k].push(i);
        }
        int ans1 = 0, ans2 = 0, lastJ = 0;

        /*
        for (int i=0; i<k; i++) {
            ans1 += max<int>(0,remainders[i].size()-1);
        }
        int left[MAX];
        int rightMin = INF, minIdx = -1;
        for (int i=0; i<k; ++i) {
            if(!remainders[i].empty()) {
                left[i] = remainders[i].front();
                remainders[i].pop();
                if (!remainders[i].empty() && rightMin > remainders[i].front()) {
                    rightMin = remainders[i].front();
                    minIdx = i;
                }
            }
        }
        while (true) {
            // move rightMin to the left
            if (minIdx == -1) break;
            ans2++;
            left[minIdx] = remainders[minIdx].front();
            remainders[minIdx].pop();

            // remove left element less than rightMin
            for (int i=0; i<k; ++i) {
                while(!remainders[i].empty() && left[i] < rightMin) {
                    left[i] = remainders[i].front();
                    remainders[i].pop();
                }
            }

            // reset rightMin
            rightMin = INF;
            minIdx = -1;
            for (int i=0; i<k; ++i) {
                if (!remainders[i].empty() && rightMin > remainders[i].front()) {
                    rightMin = remainders[i].front();
                    minIdx = i;
                }
            }
        }
        */
        ans1 = ans1%MOD;
        ans2 = ans2%MOD;
        printf("%d %d\n", ans1, ans2);
    }
}
