#include <stdio.h>
#define MAX_N 1024*1024

long long tree[2*MAX_N];
long long lazy[2*MAX_N];
long long leaf[MAX_N];

void build (int node, int start, int end) {
    if (start == end) {
        tree[node] = leaf[start];
        return;
    }
    int mid = (start + end)/2;
    build (2*node, start, mid);
    build (2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

// increment lazy of given range by val
void updateLazy (int node, int start, int end, int l, int r, long long val) {

    // 현재 node의 tree값은 caller가 참조하기 때문에 무조건 update
    if(lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > end || end < l || r < start)
        return;
    if (l <= start && end <= r) {
        tree[node] += (end-start+1)*val;
        if (start != end) {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid = (start + end)/2;
    updateLazy(2*node, start, mid, l, r, val);
    updateLazy(2*node+1, mid+1, end, l, r, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

long long queryRange (int node, int start, int end, int l, int r) {
    if (start > end ||end < l || r < start)
        return 0;
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        if (end != start) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end)/2;
    return queryRange(2*node, start, mid, l, r) + queryRange(2*node+1, mid+1, end, l, r);
}

int main() {

    // n : number of elements, m,k : number of queries
    int n, m, k, i;
    scanf("%d%d%d", &n, &m, &k);

    for (i=1; i<=n; i++)
        scanf("%lld", &leaf[i]);

    for (i=0; i<4*n && i< 2*MAX_N; i++)
        lazy[i] = 0;

    // build
    build(1, 1, n);
    int iter = m+k;
    while(iter--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a==1) {
            long long d;
            scanf("%lld", &d);
            updateLazy(1,1,n,b,c,d);
        } else if (a==2) {
            printf("%lld\n", queryRange(1,1,n,b,c));
        }
    }
    return 0;
}
