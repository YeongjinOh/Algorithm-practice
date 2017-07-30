#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
int n;

// 1. Brute force
// Tiem : O(n^3) for query
int rmq_bf(int l, int r) {
    int m = l;
    for (int i=m+1; i<=r; i++) {
        if (nums[i] < nums[m]) m = i;
    }
    return m;
}



// 2. Dynamic programming
// Time : O(n^2) to build, O(1) for query
// Space : O(n^2)

vector<vector<int> > dp;

void build_dp() {
    dp = vector<vector<int> >(n, vector<int>(n));
    for (int l=0; l<n; l++) {
        dp[l][l] = l;
        for (int r=l+1; r<n; r++) {
            int idx = dp[l][r-1];
            if (nums[idx] > nums[r])
                dp[l][r] = r;
            else
                dp[l][r] = idx;
        }
    }
}

int rmq_dp(int l, int r) {
    return dp[l][r];
}


// 3. Squre Root Decomposition
// Time : O(n) to build, O(sqrt(n)) for query
// Space : O(sqrt(n))
vector<int> dp_sq;
int sqn = 0;

void build_sq () {
    while (sqn*sqn < n) { sqn++; }
    dp_sq = vector<int> (sqn);
    for (int i=0; i<n; i++) {
        int m = i/sqn;
        if (i%sqn == 0)
            dp_sq[m] = i;
        else {
            int j = dp_sq[m];
            if (nums[j] > nums[i])
                dp_sq[m] = i;
        }
    }
}

int rmq_sq(int l, int r) {
    int m = l;
    if (l/sqn == r/sqn) {
        for (int i=l; i<=r; i++) {
            if (nums[m] > nums[i])
                m = i;
        }
    } else {
        // left
        for (int i=l+1; i%sqn != 0; i++)
            if (nums[m] > nums[i]) m = i;
        // mid
        for (int j=l/sqn+1; j<r/sqn; j++)
            if (nums[m] > nums[dp_sq[j]]) m = dp_sq[j];
        // right
        for (int i=r - (r%sqn); i<=r; i++)
            if (nums[m] > nums[i]) m = i;
    }
    return m;
}

// 4. Sparse table
// Time : O(nlogn) to build, O(1) for query
// ******* O(n) to build maybe??? ********
// Space : O(nlogn)
vector<vector<int> > M; // M[i][j] indicates the range start from i with length 2^j

int logn = 1;
void build_st() {
    while (1<<logn < n) { logn++; }
    M = vector<vector<int> > (n, vector<int> (logn));
    // j=0
    for (int i=0; i<n; i++) M[i][0] = i;
    for (int j=1; j<logn; j++) {
        for (int i=0; i+(1<<j) <= n; i++) {
            // compare l and r
            int l = M[i][j-1], r = M[i+(1<<(j-1))][j-1];
            M[i][j] = nums[l] > nums[r] ? r : l;
        }
    }
}

int rmq_st(int l, int r) {
    int len = r-l+1;
    int j = 0;
    while (1<<j < len) { j++; }
    if (1<<j == len) {
        return M[l][j];
    } else {
        j--;
        int ll = M[l][j], rr = rmq_st(l + (1<<j), r);
        return nums[ll] > nums[rr] ? rr : ll;
    }
}

// 5. Segment Tree
// Time : O(n) to build, O(logn) for query
// Space : O(n)
vector<int> seg;
void build_seg(int start, int end, int node) {
    if (start == end) {
        seg[node] = start;
        return;
    }
    int mid = (start+end)/2;
    int l = 2*node+1, r = 2*node+2;
    build_seg(start, mid, l);
    build_seg(mid+1, end, r);
    seg[node] = nums[seg[l]] > nums[seg[r]] ? seg[r] : seg[l];
}
void build_seg() {
    seg = vector<int>(4*n);
    build_seg(0, n-1, 0);
}
int query(int start, int end, int node, int l, int r) {
    if (r < start || end < l) return -1;
    if (l <= start && end <= r) return seg[node];
    int mid = (start+end)/2;
    int ll = query(start, mid, 2*node+1, l, r), rr = query(mid+1, end, 2*node+2, l, r);
    if (ll == -1) return rr;
    if (rr == -1) return ll;
    return nums[ll] > nums[rr]? rr : ll;
}

int rmq_seg(int l, int r) {
    return query(0, n-1, 0, l, r);
}

int main () {
    cin >> n;
    nums = vector<int> (n);
    for (int i=0; i<n; i++)
        nums[i] = rand()%100000;
    build_dp();
    build_sq();
    build_st();
    build_seg();
    for (int l=0; l<n; l++) {
        for (int r=l+1; r<n; r++) {
//            int idx = rmq_bf(l, r);
            int idx = rmq_dp(l, r);
//            if (idx_bf != idx_dp) printf("Wrong : rmq_dp(%d,%d) = %d not %d\n", l, r, idx_bf, idx_dp);
            int idx_sq = rmq_sq(l, r);
            if (idx != idx_sq) printf("Wrong : rmq_sq(%d,%d) = %d not %d\n", l, r, idx, idx_sq);
            int idx_st = rmq_st(l, r);
            if (idx != idx_st) printf("Wrong : rmq_st(%d,%d) = %d not %d\n", l, r, idx, idx_st);
            int idx_seg = rmq_seg(l, r);
            if (idx != idx_seg) printf("Wrong : rmq_seg(%d,%d) = %d not %d\n", l, r, idx, idx_seg);
        }
    }

    return 0;
}
