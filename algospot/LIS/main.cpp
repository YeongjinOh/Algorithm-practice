#include <iostream>
#include <cstring>
#define MAX_LEN 500

using namespace std;
int C,n;
int seq[MAX_LEN];
int d[MAX_LEN]; // DP array for bottom-up approach
int cache[MAX_LEN]; // cache for memoization

int get(int idx) {
    int &ret = cache[idx];
    if (ret != -1)
        return ret;
    int max = 0;
    for (int i = idx+1; i<n; ++i) {
        if (seq[idx] < seq[i]) {
            int cur = get(i);
            if (max < cur)
                max = cur;
        }
    }
    ret = 1+max;
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> seq[i];
        int res = 0; // global maximum

        /*  Bottom-up
        for (int i=n-1; i>=0; --i) {
            int max = 0;
            for (int j=i+1; j<n; ++j) {
                if (seq[i] < seq[j] && max < d[j])
                    max = d[j];
            }
            d[i] = 1 + max;
            if (res < d[i])
                res = d[i];
        }
        */

        /* Top-down */
        memset(cache,-1,sizeof(cache));
        for (int i=0; i<n; ++i) {
            int cur = get(i);
            if (res < cur) res = cur;
        }
        cout << res << endl;
    }
}
