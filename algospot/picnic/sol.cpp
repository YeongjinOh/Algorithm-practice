#include <iostream>
#include <cstdio>

using namespace std;

int C, n, m;
bool areFriends[10][10];
int countPairings(bool taken[10], int left) {
    bool finished = true;
    for (int i=0; i<n; ++i) if(!taken[i]) finished = false;
    if (finished) return 1;
    int ret = 0;

    for (int i=left+1; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (!taken[i] && !taken[j] && areFriends[i][j]) {
                taken[i] = taken[j] = true;
                ret += countPairings(taken,i);
                taken[i] = taken[j] = false;
            }
    return ret;
}

int main() {
    scanf("%d",&C);
    while(C--) {
        scanf("%d%d",&n,&m);
        int a,b;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                areFriends[i][j] = false;
        for (int i=0; i<m; i++) {
            scanf("%d%d",&a,&b);
            areFriends[a][b] = areFriends[b][a] = true;
        }
        bool taken[10];
        for (int i=0; i<n; i++) taken[i] = false;
        printf("%d\n",countPairings(taken,-1));
    }
    return 0;
}
