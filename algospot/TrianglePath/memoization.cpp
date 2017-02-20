#include <iostream>
#include <cstring>

using namespace std;
#define MAX_LEN 100

int tri[MAX_LEN][MAX_LEN];
int cache[MAX_LEN][MAX_LEN];
int C, n;
int max(int a, int b) { return a>b?a:b; }

int path(int i, int j) {
    int &ret = cache[i][j];
    if (ret != -1)
        return ret;
    if (j > i || i == n)
        return 0;
    ret= tri[i][j] + max(path(i+1,j),path(i+1,j+1));
    return ret;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        for (int i=0; i<n; ++i)
            for (int j=0; j<=i; ++j)
                cin >> tri[i][j];
        cout << path(0,0) << endl;
    }
    return 0;
}
