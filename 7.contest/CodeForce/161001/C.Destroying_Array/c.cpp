#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long Int;
#define MAX 1024*128
Int num[MAX];
int n;

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
        (*leaf)->maxSum = num[end]-num[start-1];
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
    num[0] = 0;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &num[i]);
    }
    for (int i=2; i<=n; i++) {
        num[i] += num[i-1];
    }
    struct node *root = (struct node*) malloc( sizeof( struct node ) );
    root->maxSum = num[n];
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
