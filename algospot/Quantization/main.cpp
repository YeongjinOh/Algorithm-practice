#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <math.h>
#define INF 987654321
#define MAX_LEN 105
using namespace std;
int C,n,m;
map<int, int> cnt;
vector<pair<int,int> > nums;
int cache[MAX_LEN][MAX_LEN];

int min (int a, int b) { return a>b?b:a; }
int calc (int start, int len, int minpos) {
    int ret = 0;
    for (int i=start; i<start+len; ++i) {
        ret += (nums[i].first-minpos)*(nums[i].first-minpos)*nums[i].second;
    }
    return ret;
}
int get(int start, int len) {

    // find minimal index
    int x = 0, nume=0;
    for (int i=start; i<start+len; ++i) {
        x += nums[i].first * nums[i].second;
        nume += nums[i].second;
    }
    int minpos = x/nume;
    return min(calc(start,len,minpos),calc(start,len,minpos+1));
}

// s is number of remaining quantization numbers
int memorize(int start, int s) {
    if (nums.size() <= s + start) return 0;
    if (s==0) {
        if (start == nums.size())
            return 0;
        else
            return INF;
    }
    int &ret = cache[start][s];
    if (ret != -1) return ret;
    ret = INF;
    int minlen = 0;
    for (int len=1; start+len <= nums.size(); ++len) {
        int cur = get(start, len) + memorize(start+len, s-1);
        if (ret > cur) {
            ret = cur;
            minlen = len;
        }
    }
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        // reset
        nums.clear();
        memset(cache,-1,sizeof(cache));
        cnt.clear();

        // get input
        cin >> n >> m;
        int num;
        for (int i=0; i<n; ++i) {
            cin >> num;
            cnt[num]++;
        }
        for (map<int,int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
            nums.push_back(make_pair(it->first,it->second));
        }
        cout << memorize (0, m) << endl;
    }

    return 0;
}
