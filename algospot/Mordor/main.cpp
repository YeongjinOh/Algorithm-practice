#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000
#define INF 987654321
#define NEGINF -1
// leaf is input, tree is segment tree
int leaf[MAX], mintree[4*MAX], maxtree[4*MAX];

int C, N, Q;

void build(int node, int left, int right) {
    if (left == right) {
        mintree[node] = maxtree[node] = leaf[left];
        return;
    }
    int mid = (left + right)/2, leftChild = node*2+1, rightChild = node*2+2;
    build(leftChild, left, mid);
    build(rightChild, mid+1, right);
    mintree[node] = min<int>(mintree[leftChild], mintree[rightChild]);
    maxtree[node] = max<int>(maxtree[leftChild], maxtree[rightChild]);
}

int queryMin (int node, int left, int right, int queryLeft, int queryRight) {
    if (right < queryLeft || queryRight < left)
        return INF;
    if (queryLeft <= left && right <= queryRight)
        return mintree[node];
    int mid = (left + right)/2, leftChild = node*2+1, rightChild = node*2+2;
    return min<int>( queryMin(leftChild, left, mid, queryLeft, queryRight),
                     queryMin(rightChild, mid+1, right, queryLeft, queryRight));
}

int queryMax (int node, int left, int right, int queryLeft, int queryRight) {
    if (right < queryLeft || queryRight < left)
        return NEGINF;
    if (queryLeft <= left && right <= queryRight)
        return maxtree[node];
    int mid = (left + right)/2, leftChild = node*2+1, rightChild = node*2+2;
    return max<int>( queryMax(leftChild, left, mid, queryLeft, queryRight),
                     queryMax(rightChild, mid+1, right, queryLeft, queryRight));
}


int main() {
    cin >> C;
    while (C--) {
        cin >> N >> Q;
        for (int i=0; i<N; i++)
            scanf("%d",leaf+i);
        build(0, 0, N-1);
        for (int i=0; i<Q; i++) {
            int left, right;
            cin >> left >> right;
            int minRange = queryMin (0, 0, N-1, left, right);
            int maxRange = queryMax (0, 0, N-1, left, right);
            cout << (maxRange - minRange) << endl;
        }
    }
}
