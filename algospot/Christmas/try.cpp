#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100001
#define MOD 20091101
int C, N, K;
int psum[MAX], cnt[MAX], last[MAX], res[MAX];
int main () {
    cin >> C;
    while(C--) {
        // reset
        memset(cnt,0,sizeof(cnt));
        cnt[0]++;
        psum[0] = 0;
        cin >> N >> K;
        for (int i=1; i<=N; i++) {
            scanf("%d",&psum[i]);
            psum[i] = (psum[i-1] + psum[i]) % K;
            cnt[psum[i]]++;
        }

        // get answer 1
        long long ans1 = 0;
        for (int i=0; i<K; i++) {
            long long cur = cnt[i];
            cur *= (long long) (cnt[i]-1);
            ans1 = (ans1 + cur/2) % MOD;
        }

        // get answer 2
        memset(last,-1,sizeof(last));
        res[0] = 0;
        last[0] = 0;
        for (int i=1; i<=N; i++) {
            res[i] = res[i-1];
            if (last[psum[i]] != -1) {
                res[i] = max<int> (res[i], res[last[psum[i]]]+1);
            }
            last[psum[i]] = i;
        }
        int ans2 = res[N];

        // print result
        printf("%lld %d\n", ans1, ans2);
    }
}
