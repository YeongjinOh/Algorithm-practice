#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define LEN 500
int num[LEN+1], cacheLIS[LEN+1];
long long cacheCnt[LEN+1];
using namespace std;
int C, N, K;
long long MAX = 1;
#define MII map<int,int>
#define VI vector<int>
#define MP make_pair
#define PB push_back
MII mp;

// O(n)
int lis(int start) {
    int& ret = cacheLIS[start];
    if (ret != -1) return ret;
    ret = 0;
    for (int next = start+1; next <= N; ++next) {
        if (num[start] < num[next]) {
            int cur = lis(next);
            if (ret < cur)
                ret = cur;
        }
    }
    ret++;
    return ret;
}

// O(n)
long long count(int start) {
    if (lis(start) == 1) return 1;
    long long& cnt = cacheCnt[start];
    if (cnt != -1) return cnt;
    cnt = 0;
    for (int next = start+1; next<=N; ++next) {
        if (num[start] < num[next] && lis(start) == lis(next) + 1) {
            cnt += count(next);
            if (cnt > MAX) {
                cnt = MAX;
                return MAX;
            }
        }
    }
    return cnt;
}

// O(n^2)
void build(int start, long long skip, VI& res) {
    res.PB(num[start]);
    for (MII::iterator iter = ++(mp.find(num[start])); iter != mp.end();  ++iter) {
        int next = iter->second;
        if (lis(start) == lis(next) + 1 ) {
            long long cntNext = count(next);
            if (skip <= cntNext) {
                build(next, skip, res);
                return;
            }
            skip -= cntNext;
        }
    }
}

int main() {
    cin >> C;
    MAX <<= 32;
    while (C--) {
        mp.clear();
        cin >> N >> K;
        for (int i=1; i<=N; ++i) {
            cin >> num[i];
            mp.insert(MP(num[i],i));
        }
        num[0] = 0;
        mp.insert(MP(0,0));
        memset(cacheLIS, -1, sizeof(cacheLIS));
        memset(cacheCnt, -1, sizeof(cacheCnt));
        VI res;
        build(0, (long long)K,res);
        cout << res.size()-1 << endl;
        for (int i=1; i<res.size(); ++i)
            cout << res[i] << " ";
        cout << endl;
    }
}
