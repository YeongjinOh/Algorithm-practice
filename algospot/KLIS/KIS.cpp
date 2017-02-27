#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define LEN 500
int num[LEN];
using namespace std;
int C, N, K;
// dp[i][j] means number of LIS with length i+1 which starts from j-th element
long long dp[LEN][LEN];
long long sum[LEN];
map<int,int> mp;

void build(int i, int j, int k, vector<int>& res) {
    map<int,int>::iterator iter = j<0 ? mp.begin():++(mp.find(num[j]));
    if (i == 0) {
        for (; iter != mp.end(); ++iter) {
            if (iter->second > j) k--;
            if (k==0) break;
        }
        res.push_back(iter->first);
        return;
    }
    for (; iter != mp.end(); ++iter) {
        if (iter->second > j) {
            if (k <= dp[i][iter->second]) {
                res.push_back(iter->first);
                build(i-1, iter->second, k, res);
                return;
            }
            k -= dp[i][iter->second];
        }
    }
}

int main() {
    cin >> C;
    long long MAX = 1;
    MAX <<= 31;
    while (C--) {
        mp.clear();
        cin >> N >> K;
        for (int i=0; i<N; ++i) {
            cin >> num[i];
            mp.insert(make_pair(num[i],i));
        }
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for (int j=0; j<N; ++j)
            dp[0][j] = 1;
        sum[0] = N;

        // build sum takes O(n^3)
        for (int i=1; i<N; ++i) {
            for (int j=N-i-1; j>=0; --j) {
                for (int k=j+1; k<N; ++k) {
                    if (num[j] < num[k]) {
                        dp[i][j] += dp[i-1][k];
                        if (dp[i][j] >= MAX) {
                            dp[i][j] = MAX;
                            break;
                        }
                    }
                }
                sum[i] += dp[i][j];
            }
        }


        // get length (= idx+1)
        // takes O(n)
        int idx = N-1;
        while(true) {
            if (K<=sum[idx]) break;
            K -= sum[idx--];
        }
        cout << idx+1 << " " << endl;

        // print
        bool debug = false;
        if (debug) {
            for (int i=0; i<N; ++i) {
                for (int j=0; j<N; ++j) {
                    cout << dp[i][j] << " ";
                }
                cout << " sum : " << sum[i] << endl;
            }
            for (map<int,int>::iterator iter=++(mp.find(2)); iter != mp.end(); iter++) {
                printf("(%d,%d)\n",iter->first, iter->second);
            }
        }

        vector<int> res;

        // building res takes O(n^2)
        build(idx, -1, K, res);
        for (int i=0; i<res.size(); ++i)
            cout << res[i] << " ";
        cout<<endl;
    }
}
