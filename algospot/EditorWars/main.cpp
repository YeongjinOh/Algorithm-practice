#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C, n, m;

struct DisjointGroup {
    vector<int> size, parent, height, enemy;
    DisjointGroup(int n) : size(n), parent(n), height(n,1), enemy(n, -1) {
        for (int i=0; i<n; i++)
            parent[i] = i;
    }
    int find (int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void merge (int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (height[u] > height[v]) swap(u,v);
        parent[u] = v;
        if (enemy[v] == -1)
            enemy[v] = enemy[u];
        height[v] += height[u];
    }

    int getEnemy (int u) {
        if (enemy[u] < 0) return -1;
        return find(enemy[u]);
    }

    void setEnemy (int u, int e) {
        enemy[find(u)] = e;
    }

    int getMaxSize () {
        int parentIdx, enemyIdx, res = 0;
        vector<bool> visit(height.size());
        for (int i=0; i<height.size(); ++i) {
            parentIdx = find(i);
            if (visit[parentIdx]) continue;
            visit[parentIdx] = true;
            enemyIdx = getEnemy(parentIdx);
            if (enemyIdx >= 0) {
                res += max<int> (height[parentIdx], height[enemyIdx]);
                visit[enemyIdx] = true;
            } else
                res += height[parentIdx];
        }
        return res;
    }
};

int main() {
    cin >> C;
    while (C--) {
        cin >> n >> m;
        int a, b, ea, eb;
        DisjointGroup dg(n);
        bool contra = false;
        char comment[4];
        for (int commentNum = 1; commentNum <= m; commentNum++) {
            scanf("%s%d%d",comment,&a,&b);
            if (contra) continue;

            a = dg.find(a); b = dg.find(b);
            ea = dg.getEnemy(a); eb = dg.getEnemy(b);
            if (comment[0] == 'A') {
                if (a == b) continue;
                if (ea == b || eb == a) {
                    printf("CONTRADICTION AT %d\n", commentNum);
                    contra = true;
                }
                if (ea >= 0 && eb >= 0) {
                    dg.merge(ea, eb);
                }
                dg.merge(a, b);

            } else {
                if (a == b) {
                    printf("CONTRADICTION AT %d\n", commentNum);
                    contra = true;
                }
                dg.setEnemy(a, b);
                dg.setEnemy(b, a);
                if (ea >= 0)
                    dg.merge(ea, b);
                if (eb >= 0)
                    dg.merge(a, eb);
            }
        }
        if (!contra)
            printf("MAX PARTY SIZE IS %d\n", dg.getMaxSize());
    }
    return 0;
}
