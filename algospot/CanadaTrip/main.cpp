#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 5000
struct city {
    int start;
    int end;
    int gap;
};
using namespace std;
int C, N;
int K;
city cities[LEN];
int min (int a, int b) { return a<b?a:b; }
bool check(int pos) {
    int cnt = 0;
    for (int i=0; i<N; ++i) {
        city c = cities[i];
        if (c.start <= pos) {
            int cur = (min(pos,c.end)-c.start)/c.gap + 1;
            cnt += cur;
        }
    }
    return cnt >= K;
}
int main() {
    cin >> C;
    while (C--) {
        scanf("%d%d",&N,&K);
        for (int i=0; i<N; ++i) {
            int L, M, G;
            scanf("%d%d%d",&L,&M,&G);
            cities[i].start = L-M;
            cities[i].end = L;
            cities[i].gap = G;
        }
        long long max = 1;
        max = max<<31;
        max--;
        int l = 0, r = (int)max;
        r = r<<31;
        while(l!=r) {
            int mid = (l+r)/2;
            if (check(mid)) r = mid;
            else l = mid+1;
        }
        cout << l << endl;
    }
}
