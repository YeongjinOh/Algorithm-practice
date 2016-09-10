#include <stdio.h>
#define MAX 100000
// start from index 1 when using array
// left child = 2*node, right child = 2*node+1

int lazy[MAX*4];
int coin[MAX+1];
int cnt[MAX+1];

// just increment by 1
void updateRange(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return;
    if (l <= start && end <= r) {
        lazy[node]++;
        return;
    }
    int mid = (start + end)/2;
    updateRange(2*node, start, mid, l, r);
    updateRange(2*node+1, mid+1, end, l, r);
}

void updateAll(int node, int start, int end) {
    if (start == end) {
        coin[start] = lazy[node];
        return;
    }
    int mid = (start + end)/2;
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
    lazy[node] = 0;
    updateAll(2*node, start, mid);
    updateAll(2*node+1, mid+1, end);
}

int main() {
    // n : number of elements, m : number of updateRange
    int i, n, m;
    scanf("%d", &n);
    // build lazy
    for (i=0; i<4*n; i++)
        lazy[i] = 0;
    scanf("%d", &m);
    while(m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        updateRange(1, 1, n, l, r);
    }


    // update all
    updateAll(1,1,n);

    // initialize cnt
    for (i=1; i<=n; i++)
        cnt[i] = 0;

    // count coins
    for (i=1; i<=n; i++)
        cnt[coin[i]]++;

    // acculmulate coins
    for (i=n-1; i>=0; i--)
        cnt[i] += cnt[i+1];

    // q : number of queries
    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d",&x);
        printf("%d\n",cnt[x]);
    }


    return 0;
}
