#include <iostream>
#include <vector>

using namespace std;

#define MAX 1024*1024
long long leaf[MAX], tree[2*MAX];
int n, m, k;

void build (int node, int left, int right) {
    if (left == right) {
        tree[node] = leaf[left];
        return;
    }
    int mid = (left + right)/2, leftChild = 2*node+1, rightChild = 2*node+2;
    build(leftChild, left, mid);
    build(rightChild, mid+1, right);
    tree[node] = tree[leftChild] + tree[rightChild];
}

long long query (int node, int left, int right, int queryLeft, int queryRight) {
    if (right < queryLeft || queryRight < left)
        return 0;
    if (queryLeft <= left && right <= queryRight)
        return tree[node];
    int mid = (left+right)/2, leftChild = 2*node+1, rightChild = 2*node+2;
    return query(leftChild, left, mid, queryLeft, queryRight) + query(rightChild, mid+1, right, queryLeft, queryRight);
}

// update(increase) idx-th element by inc
void update (int node, int left, int right, int idx, int inc) {
    if (idx < left || right < idx) return;
    tree[node] += inc;
    if (left == right) return;
    int mid = (left+right)/2, leftChild = 2*node+1, rightChild = 2*node+2;
    update(leftChild, left, mid, idx, inc);
    update(rightChild, mid+1, right, idx, inc);
}

void change (int idx, int value) {
    int inc = value - query(0, 0, n, idx, idx);
    update(0, 0, n, idx, inc);
}


int main() {
    scanf("%d%d%d",&n,&m,&k);

    leaf[0] = 0;
    for (int i=1; i<=n; i++) {
        scanf("%lld", leaf+i);
    }
    // build segment tree
    build(0, 0, n);

    m += k;
    int a, b, c;
    while(m--) {
        scanf("%d%d%d",&a,&b,&c);
        if (a == 1) {
            change(b, c);
        } else {
            printf("%lld\n", query(0,0,n,b,c));
        }
    }

    return 0;
}
