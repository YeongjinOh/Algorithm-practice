#include <iostream>
using namespace std;

#define LEN 1000
int arr[LEN];
int seg[4*LEN];
// 구간 합
// 구간 update
void build(int start, int end, int node) {
    if (start == end) {
        seg[node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(start, mid, node*2+1);
    build(mid+1, end, node*2+2);
    seg[node] = seg[node*2+1] + seg[node*2+2];
}

int query(int start, int end, int node, int l, int r) {
    if (start > r || end < l) return 0;
    if (l <= start && end <= r) return seg[node];
    int mid = (start+end)/2;
    return query(start, mid, node*2+1, l, r) + query(mid+1, end, node*2+2, l, r);
}

// build와 query를 섞어서 구현 -> return int
int update(int start, int end, int node, int l, int r) {
    if (start > r || end < l)
        return seg[node];
    if (start == end) {
        return ++seg[node];
    }
    int mid = (start+end)/2;
    return seg[node] = update(start, mid, 2*node+1, l, r) + update(mid+1, end, 2*node+2, l, r);
}
int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    build(0, n-1, 0);
    int m; cin >> m;
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a==1) {
            printf("[%d,%d] : %d\n", b, c, query(0, n-1, 0, b, c));
        } else {
            update(0, n-1, 0, b, c);
        }
    }

}
