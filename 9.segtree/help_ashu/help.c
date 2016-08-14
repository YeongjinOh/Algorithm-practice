#include <stdio.h>
#include <stdbool.h>

//#define MAX_N 1000
#define MAX_N 100000

// number of odds
int tree[2*MAX_N];
int lazy[2*MAX_N];
int leaf[MAX_N];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = leaf[start];
        return;
    }
    int mid = (start + end)/2;
    build(2*node+1, start, mid);
    build(2*node+2, mid+1, end);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

// val will be 1 or -1
void update(int node, int start, int end, int idx, int val) {
    if (idx < start || end < idx)
        return;
    if (start == end) {
        tree[node] += val;
        return;
    }
    int mid = (start + end)/2;
    update(2*node+1, start, mid, idx, val);
    update(2*node+2, mid+1, end, idx, val);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

int query (int node, int start, int end, int l, int r) {
    if (end < l || start > r)
        return 0;
    if (l <= start && end <= r)
        return tree[node];
    int mid = (start + end)/2;
    return query(2*node+1, start, mid, l, r) + query(2*node+2, mid+1, end, l, r);
}

int main() {
    int n, i, q, tmp;
    // number of elements;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        leaf[i] = tmp%2;
    }
    build(0,0,n-1);
    scanf("%d", &q);
    while(q--) {
        int type, l, r;
        scanf("%d%d%d",&type,&l,&r);
        switch(type) {
            case 0:
                if (r%2 != leaf[l-1]) {
                    int val = r%2 - leaf[l-1];
                    leaf[l-1] = r%2;
                    update(0,0,n-1,l-1,val);
                }
                break;
            case 1:
                printf("%d\n", r-l+1-query(0,0,n-1,l-1,r-1));
                break;
            case 2:
                printf("%d\n", query(0,0,n-1,l-1,r-1));
                break;
        }
    }

    return 0;
}
