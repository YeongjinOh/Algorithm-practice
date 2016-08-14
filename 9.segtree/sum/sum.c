#include <stdio.h>
#define MAX_INPUT 10000

int tree[MAX_INPUT*2-1];
int lazy[MAX_INPUT*2-1];
int leaf[MAX_INPUT];

void build(int node, int start, int end) {
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

    // if lazy, update
    if (lazy[node] != 0) {
        tree[node] += lazy[node]*(end-start+1);
        // check if it has children
        if (start != end) {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }

    // out of range
    // ** start could be bigger than end
    if (start > end || end < l || start > r)
        return;
    if (l <= start && end <= r) {
        tree[node] += (end-start+1)*val;
        if (start != end) {
            lazy[2*node+1] += val;
            lazy[2*node+2] += val;
        }
        return;
    }
    int mid = (start + end)/2;
    updateRange(2*node+1, start, mid, l, r, val);
    updateRange(2*node+2, mid+1, end, l, r, val);
    tree[node] = tree[2*node+1]+tree[2*node+2];
}

int queryRange(int node, int start, int end, int l, int r) {
    if (start > end || end < l || start > r)
        return 0;
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node]=0;
    }
   if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end)/2;
    return queryRange(2*node+1, start, mid, l, r) + queryRange(2*node+2, mid+1, end, l, r);
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
    // get input values
    for (i=0; i<n; i++)
        scanf("%d",&leaf[i]);
    // initialize lazy
    for (i=0; i<3*n; i++)
        lazy[i]=0;
    // build segment tree
    build(0,0,n-1);

    // query
    while(1) {
        int l, r, val;
        scanf("%d%d%d", &l, &r, &val);
            printf("updateRange from %d to %d by %d\n",l ,r, val);
            updateRange(0, 0, n-1, l, r, val);
            for (i=0; i<16; i++)
               printf("%d ", tree[i]);
            printf("\n");
            for (i=0; i<16; i++)
               printf("%d ", lazy[i]);
            printf("\nqueryRange = %d\n", queryRange(0, 0, n-1, l, r));
    }

}
