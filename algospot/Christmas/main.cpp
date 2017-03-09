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
int d[MAX] = {0}, cnt[MAX], cache[MAX], lastI[MAX], nextI[MAX];

// start should be included
int search (int start) {
    if (start > n) return 0;
    int &ret = cache[start];
    if (ret != -1) return ret;

    ret = search(start+1);
    if (nextI[start])
        ret = max<int> (ret, search(nextI[start])+1);
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> n >> k;
        memset(cnt,0,sizeof(cnt));
        memset(lastI,-1,sizeof(lastI));
        memset(nextI,0,sizeof(nextI));
        lastI[0] = 0;
        d[0] = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d",&d[i]);
            d[i] = (d[i-1] + d[i])%k;
            cnt[d[i]]++;
            if (lastI[d[i]] != -1) {
                nextI[lastI[d[i]]] = i;
            }
            lastI[d[i]] = i;
        }
        cnt[0]++;
        long long ans1 = 0, ans2;

        ///////////////////////////////////////////////////////////
        // important
        // use long long type since cnt <= 10^5, ans1 <= 10^10
        // ////////////////////////////////////////////////////////
        for (int i=0; i<k; i++) {
            ans1 += (((long long)cnt[i]*(cnt[i]-1))) / 2;
            ans1 = ans1%MOD;
        }
        memset(cache, -1, sizeof(cache));
        ans2 = search(0);

        ans1 = ans1%MOD;
        ans2 = ans2%MOD;
        printf("%lld %lld\n", ans1, ans2);
    }
}
