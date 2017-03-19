#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree(150000);

int n, k, a, b, ans;

// count sum of all distance between all pairs
// 본 문제에서 k=1일때와 같은 결과를 갖는다.
vector<int> dfs (int cur, int pre) {
    vector<int> res(n);
    res[0] = 1;
    vector<int> sum, size;
    int sizesum = 0;
    for (int i=0; i<tree[cur].size(); i++) {
        int next = tree[cur][i];
        if (pre == next) continue;

        vector<int> tmp = dfs(next, cur);
        int tmpsum = 0;
        int sz = 0;
        for (int j=0; j<tmp.size(); j++) {
            tmpsum += tmp[j]*(j+1);
            res[j+1] += tmp[j];
            sz += tmp[j];
        }
        sizesum += sz;
        size.push_back(sz);
        sum.push_back(tmpsum);
    }
    for (int i=0; i<sum.size(); i++) {
        ans += (sizesum + 1 - size[i])*sum[i];
    }
    return res;
}

int main() {

    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        scanf("%d%d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ans = 0;
    dfs (1, 0);
    printf("%d\n",ans);

    return 0;
}
