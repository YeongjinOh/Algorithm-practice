#include <iostream>
#include <cstring>

using namespace std;
int C;
double cache[1001][1001];
double get(int n, int m) {
    if (n <= 0) return 1;
    if (m == 0) return 0;
    double &ret = cache[n][m];
    if (ret != -1) return ret;
   ret = (3*get(n-2,m-1)+get(n-1,m-1))/4;
    return ret;
}
int main() {
    cin >> C;
    int n,m;
    while (C--) {
        cin >> n >> m;
        for (int i=0; i<=n; ++i)
            for (int j=0; j<=m; ++j)
                cache[i][j] = -1;
        printf("%.10lf\n",get(n,m));
    }
}
