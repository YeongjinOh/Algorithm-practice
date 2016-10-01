#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long Int;
#define MAX 1024*128
Int tree[2*MAX];
Int num[MAX];
int n;
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

Int queryRange(int node, int start, int end, int l, int r) {
    if (end < l || r < start)
        return 0;

    if (l <= start && end <= r)
        return tree[node];
    Int mid = (start + end)/2;
    return queryRange(2*node, start, mid, l, r) + queryRange(2*node+1, mid+1, end, l, r);
}

Int query(int l, int r) {
    return queryRange(1, 1, n, l, r);
}

Int max(Int a, Int b) {return a>b?a:b;}

struct node {
    int cut;
    Int maxSum;
    struct node *left;
    struct node *right;
};

long long insertAndGetMax(int start, int end, int cut, struct node **leaf) {
    if (start > end) {
        (*leaf) = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->maxSum = 0;
        return 0;
    }
    if( (*leaf) == 0 ) {
        (*leaf) = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->cut = -1;
        (*leaf)->maxSum = query(start,end);
        (*leaf)->left = 0;
        (*leaf)->right = 0;
        return (*leaf)->maxSum;
    }
    if((*leaf)->cut == -1) {
        (*leaf)->cut = cut;
        (*leaf)->maxSum = max(insertAndGetMax(start, cut-1, cut, &(*leaf)->left), insertAndGetMax(cut+1, end, cut, &(*leaf)->right)) ;
        return (*leaf)->maxSum;
    }
    if ((*leaf)->cut < cut) {
        (*leaf)->maxSum = max((*leaf)->left->maxSum, insertAndGetMax((*leaf)->cut+1, end, cut, &(*leaf)->right));
        return (*leaf)->maxSum;
    } else {
        (*leaf)->maxSum = max((*leaf)->right->maxSum, insertAndGetMax(start, (*leaf)->cut-1, cut, &(*leaf)->left));
        return (*leaf)->maxSum;
    }
}
int main() {

    // get input
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%lld", &num[i]);
    }
    build(1, 1, n);
    struct node *root = (struct node*) malloc( sizeof( struct node ) );
    root->maxSum = query(1, n);
    root->cut = -1;
    root->left = 0;
    root->right = 0;
    int cut;
    for (int i=1; i<=n; i++) {
        scanf("%d",&cut);
        printf("%lld\n", insertAndGetMax(1,n,cut,&root));
    }
    return 0;
}
