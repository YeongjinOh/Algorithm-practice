#include <iostream>
#include <cstring>

using namespace std;
#define MAX_LEN 100

int tri[MAX_LEN][MAX_LEN];
int cache[MAX_LEN];
int C, n;
int max(int a, int b) { return a>b?a:b; }

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        for (int i=0; i<n; ++i)
            for (int j=0; j<=i; ++j)
                cin >> tri[i][j];
        for (int i=0; i<n; ++i)
            for (int j=i; j>=0; --j) {
                if (j == i) {
                    cache[j] = cache[j-1] + tri[i][j];
                    continue;
                } else if (j == 0) {
                    cache[j] += tri[i][j];
                    continue;
                }
                cache[j] = tri[i][j] + max(cache[j], cache[j-1]);
            }
        int res = 0;
        for (int i=0; i<n; i++)
            res = max(res,cache[i]);
        cout << res << endl;
    }
    return 0;
}
