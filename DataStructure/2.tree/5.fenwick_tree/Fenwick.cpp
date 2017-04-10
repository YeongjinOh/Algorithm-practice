#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree {
    vector<int> tree;
    FenwickTree (int n) : tree(n+1) { }

    // A[0..pos]의 부분합을 구한다.
    int sum (int pos) {

        // 내부적으로 tree[1..pos+1]의 부분합이다.
        pos++;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main() {
    cout << "numbers:";
    int n;
    cin >> n;
    FenwickTree fenwick(n);
    for (int i=0; i<n; i++) {
        fenwick.add(i, i+1);
    }
    while (true) {
        int left, right;
        cin >> left >> right;
        cout << fenwick.sum(right) - fenwick.sum(left-1) << endl;
    }
    return 0;
}
