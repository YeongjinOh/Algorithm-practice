#include <iostream>
#include <vector>

using namespace std;

long long ans = 0;

vector<long long> dfs(int v, int f, int k, vector<vector<int> >& e) {
    vector<long long> res(k+1);
    res[0] = 1;
    long long sum = 1;
    for (int i = 0; i < e[v].size(); ++i) {
        int vv = e[v][i];
        if (vv == f) {
            continue;
        }
        auto tmp = dfs(vv, v, k, e);

        long long tmpsum = 0;
        for (int j = 0; j < k; ++j) {
            tmpsum += tmp[j];
        }

        tmp[k] += tmp[0];
        long long c = tmp[k-1];
        for (int j = k-2; j >= 0; --j) {
            tmp[j+1] = tmp[j];
        }
        tmp[0] = c;

        ans += sum * tmp[k] + tmpsum * res[k];
        sum += tmpsum;

        for (int j = 1; j < k; ++j) {
            for (int tmpj = 1; tmpj < k; ++tmpj) {
                if (j + tmpj <= k) {
                    ans -= res[j] * tmp[tmpj];
                }
            }
        }
        for (int j = 0; j <= k; ++j) {
            res[j] += tmp[j];
        }
    }
    return res;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int> > e(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0, k, e);
    cout << ans << endl;
}
