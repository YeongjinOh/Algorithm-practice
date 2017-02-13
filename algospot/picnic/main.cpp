#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <list>
#include <vector>

using namespace std;

vector<int> relation[50];
int C, n, m;
int cntt = 0;
int count(bool * matched, int a, int b) {
    cntt++;
    if (a>=0)
        matched[a] = true;
    if (b>=0)
        matched[b] = true;
    int base = -1;
    for (int i=0; i<n; i++) {
        if (matched[i])
            continue;
        base = i;
        break;
    }
    if (base == -1)
        return 1;
    int cnt = 0;
    for (int i=0; i<relation[base].size(); i++) {
        int cmp = relation[base][i];
        if (base > cmp || matched[cmp])
            continue;
        bool mcopy[50];
        for (int j=0; j<n; j++) {
            mcopy[j] = matched[j];
        }
        cnt += count(mcopy, base, cmp);
    }
    return cnt;
}

int main() {

    scanf("%d",&C);
    while(C--) {
        scanf("%d%d",&n,&m);
        int a,b;
        for (int i=0; i<m; i++) {
            scanf("%d%d",&a,&b);
            relation[a].push_back(b);
            relation[b].push_back(a);
        }
        bool matched[50];
        for (int i=0; i<n; i++) matched[i] = false;
        printf("%d\n",count(matched,-1,-1));
        for (int i=0; i<n; i++)
            relation[i].clear();
        printf("cntt:%d\n",cntt);
    }
    return 0;
}
