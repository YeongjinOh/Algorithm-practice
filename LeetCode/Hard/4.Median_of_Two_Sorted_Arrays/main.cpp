#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int findKth (vector<int> &nums1, vector<int> &nums2, int l1, int r1, int l2, int r2, int k) {

    printf("k:%d [%d,%d] [%d,%d]\n", k, l1, r1, l2, r2);
    if (l1>r1) {
        return nums2[l2+k-1];
    } else if (l2>r2) {
        return nums1[l1+k-1];
    }

    int mid1 = (l1+r1)/2, mid2 = (l2+r2)/2;
    int sz1 = mid1-l1+1, sz2 = mid2-l2+1;
    if (sz1 + sz2 >= k) {
        if (nums1[mid1] > nums2[mid2]) {
            return findKth(nums1, nums2, l1, mid1, l2, r2, k);
        } else {
            return findKth(nums1, nums2, l1, r1, l2, mid2, k);
        }
    } else {
        if (nums1[mid1] > nums2[mid2]) {
            return findKth(nums1, nums2, mid1+1, r1, l2, r2, k-(mid1-l1+1));
        } else {
            return findKth(nums1, nums2, l1, r1, mid2+1, r2, k-(mid2-l2+1));
        }
    }
    return -1;
}


// mock interview answer by hj
int b_search2(vector<int>& arr1, vector<int>& arr2, int l1, int r1, int l2, int r2, int k) {
    int md1 = (l1 + r1)/2;
    int md2 = (l2 + r2)/2;
    int md1_val = arr1[md1];
    int md2_val = arr2[md2];
    printf("k:%d [%d,%d] [%d,%d] md1:%d md2:%d\n", k, l1, r1, l2, r2, md1, md2);
    if (md1_val > md2_val) {
        return b_search2(arr2, arr1, l2, r2, l1, r1, k);
    }
    int arr1_left_sz = md1-l1 + 1;
    int arr2_left_sz = md2-l2 + 1;
    if (l1 > r1) {
        return arr2[l2 + k-1];
    } else if (l2 > r2) {
        return arr1[l1 + k-1];
    }
    if (arr1_left_sz == 1 && k == 1) return arr1[md1];
    if (arr1_left_sz + arr2_left_sz == 2 && k == 2) return arr2[md2];

    if (arr1_left_sz >= k) {
        return b_search2(arr1, arr2, l1, md1, l2, md2, k);
    } else if (arr1_left_sz + arr2_left_sz >= k) {
        return b_search2(arr1, arr2, l1, r1, l2, md2, k);
    } else {
        return b_search2(arr1, arr2, md1 + 1, r1, l2, r2, k-arr1_left_sz);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i=0; i<n; i++) cin >> nums1[i];
    for (int i=0; i<m; i++) cin >> nums2[i];
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> merged;
    for (int i=0; i<n; i++) merged.push_back(nums1[i]);
    for (int i=0; i<m; i++) merged.push_back(nums2[i]);
    sort(merged.begin(), merged.end());
    for (int k=1; k <= n+m; k++) {
        int kth = findKth(nums1, nums2, 0, n-1, 0, m-1, k);
//        int kth = b_search2(nums1, nums2, 0, n-1, 0, m-1, k);
        cout << kth << endl;
        if (kth != merged[k-1]) printf("Wrong! kth is %d\n", merged[k-1]);
    }
    return 0;
}
