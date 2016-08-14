#include <stdio.h>
#define MAX_INPUT 10000

int tree[MAX_INPUT*2-1];
int leaf[MAX_INPUT];

void build(int node, int start, int end) {
    printf("node:%d s:%d e:%d\n",node,start,end);
    if (start == end) {
        tree[node] = leaf[start];
    } else {
        int mid = (start + end) / 2;
        build(2*node+1, start, mid);
        build(2*node+2 ,mid+1, end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}

// increment leaf[idx] by val
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        leaf[idx] += val;
        tree[node] += val;
    } else if (idx < start || idx > end) {
        return;
    } else {
        int mid = (start + end)/2;
        update(2*node+1, start, mid, idx, val);
        update(2*node+2, mid+1, end, idx, val);
        tree[node] += val;
    }
}

// increment range
void updateRange(int node, int start, int end, int l, int r, int val) {

}

int query (int node, int start, int end, int l, int r)  {
    if (r < start || end < l) {
        return 0;
    } else if (l <= start && end <= r) {
        return tree[node];
    } else {
        int mid = (start + end)/2;
        return query(2*node+1, start, mid, l, r) + query(2*node+2, mid+1, end, l, r);
    }
}


int main() {
    // n should be less than MAX_INPUT
    int n, i;
    scanf("%d", &n);
    for (i=0; i<n; i++)
        scanf("%d",&leaf[i]);

    // build segment tree
    build(0,0,n-1);

    update (0, 0, n-1, 2, 10);

    // query
    while(1) {
        int l, r;
        scanf("%d%d",&l, &r);
        printf("sum:%d\n", query(0, 0, n-1, l, r));
    }

}
