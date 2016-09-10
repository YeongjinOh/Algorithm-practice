#include <cstdio>
#define MAX 1024*1024

typedef long long Int;
Int tree[2*MAX];
Int lazy[2*MAX];
Int num[MAX];

void build (Int node, int start, int end) {
    if (start == end) {
        tree[node] = num[start];
        return;
    }
    Int mid = (start + end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

// increment given range [l,r] by diff
void updateRange(Int node, int start, int end, int l, int r, int diff) {
    // lazy propagation
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (r < start || end < l)
        return;
    if (l <= start && end <= r) {
        tree[node] += (end-start+1)*diff;
        if (start != end) {
            lazy[2*node] += diff;
            lazy[2*node+1] += diff;
        }
        return;
    }

    Int mid = (start + end)/2;
    updateRange(2*node, start, mid, l, r, diff);
    updateRange(2*node+1, mid+1, end, l, r, diff);
    tree[node] = tree[2*node] + tree[2*node+1];
}

Int queryRange(int node, int start, int end, int l, int r) {
    if (end < l || r < start)
        return 0;
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (l <= start && end <= r)
        return tree[node];
    Int mid = (start + end)/2;
    return queryRange(2*node, start, mid, l, r) + queryRange(2*node+1, mid+1, end, l, r);
}


int main() {

    // get input
    Int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    for (Int i=1; i<=n; i++) {
        scanf("%lld", &num[i]);
    }
    build(1, 1, n);
    Int a, b, c, d;
    for (Int i=0; i<m+k; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a==1) {
            scanf("%lld", &d);
            updateRange(1,1,n,b,c,d);
        } else {
            printf("%lld\n", queryRange(1,1,n,b,c));
        }
    }

    return 0;
}
