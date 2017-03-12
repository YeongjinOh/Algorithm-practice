#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree {
    vector<long long> tree;
    FenwickTree(int n) : tree(n+1) { }

    long long sum (int pos) {
        long long ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    long long range (int left, int right) {
        return sum(right) - sum(left-1);
    }
    void add (int pos, long long val) {
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
    void change (int pos, long long val) {
        add(pos, val - range(pos,pos));
    }
};

int main() {
    int n, m, k;
    long long num;
    scanf("%d%d%d",&n,&m,&k);
    FenwickTree fenwick(n);

    for (int i=1; i<=n; i++) {
        scanf("%lld", &num);
        fenwick.change(i,num);
    }
    m += k;
    int a, b;
    long long c;
    while(m--) {
        scanf("%d%d%lld",&a,&b,&c);
        if (a == 1) {
            fenwick.change(b, c);
        } else {
            printf("%lld\n", fenwick.range(b,(int)c));
        }
    }

    return 0;
}
