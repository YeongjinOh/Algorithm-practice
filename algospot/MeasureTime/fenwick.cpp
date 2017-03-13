#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C, n;
#define MAX 1000010

struct FenwickTree {
    int tree[MAX];

    FenwickTree() {n=0;}

    // sum of tree[1 .. pos]
    int sum (int pos) {
        pos++;
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }

    ////////////////////////////////////////////////////
    // important
    // if pos can be 0, should use (pos++)
    // otherwise, infinite loop
    // /////////////////////////////////////////////////
    void add (int pos, int val) {
        pos++;
        while(pos < MAX) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }

    void clear () {
        memset(tree,0,sizeof(tree));
    }
};

FenwickTree fenwick;

int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &n);

        long long sum = 0;
        fenwick.clear();

        int num;
        for (int i=1; i<=n; i++) {
            scanf("%d", &num);
            fenwick.add(num, 1);
            sum += i-fenwick.sum(num);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
