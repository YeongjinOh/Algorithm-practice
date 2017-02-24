#include <iostream>
#include <cstring>
using namespace std;
int C,n;
int tri[100][100], cache[100][100], cnt[100][100];

// (i,j)부터 시작하는 maximal path
int get (int i, int j) {
    if (i >= n || j < 0 || i < j) return 0;
    int &ret = cache[i][j];
    if (ret != -1) return ret;

    int d = get(i+1,j), dr = get(i+1,j+1);
    if (i == n-1)
        cnt[i][j] = 1;
    else {
        if (d == dr) cnt[i][j] = cnt[i+1][j] + cnt[i+1][j+1];
        else if (d > dr) cnt[i][j] = cnt[i+1][j];
        else cnt[i][j] = cnt[i+1][j+1];
    }
    ret = tri[i][j] + max(d,dr);
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=i; ++j) {
                cin >> tri[i][j];
            }
        }
        memset(cache,-1,sizeof(cache));
        memset(cnt,0,sizeof(cnt));
        get(0,0);
        cout << cnt[0][0] << endl;
    }
}
