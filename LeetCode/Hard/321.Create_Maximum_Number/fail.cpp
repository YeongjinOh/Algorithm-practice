#include <iostream>
#include <vector>
using namespace std;

// I tried to solve this problem using DP with O(nmk)
// but Failed. and it's bad
//
class Solution {
    public:
        void generate(const vector<int>& nums1, const vector<int>& nums2, vector<int>& res, vector<vector<vector<int> > >& cache, int i, int j, int s) {
            printf("%d %d %d\n", i, j, s);
            int n = nums1.size(), m = nums2.size(), k = res.size();
            if (s == k || i > n || j > m || (n-i) + (m-j) < k-s) return;
            if (cache[i][j][s] != -1) return;
            if ((n-i) + (m-j) == (k-s)) {
                if (i == n) {
                    cache[i][j][s] = res[s] = nums2[j];
                    generate(nums1, nums2, res, cache, i, j+1, s+1);
                    return;
                } else if (j == m || nums1[i] > nums2[j]) {
                    cache[i][j][s] = res[s] = nums1[i];
                    generate(nums1, nums2, res, cache, i+1, j, s+1);
                    return;
                } else if (nums1[i] < nums2[j] ){
                    cache[i][j][s] = res[s] = nums2[j];
                    generate(nums1, nums2, res, cache, i, j+1, s+1);
                    return;
                } else {
                    cache[i][j][s] = res[s] = nums1[i];
                    generate(nums1, nums2, res, cache, i, j+1, s+1);
                    generate(nums1, nums2, res, cache, i+1, j, s+1);
                }
            }
            if (i == n) {
                generate(nums1, nums2, res, cache, i, j+1, s);
                cache[i][j][s] = cache[i][j+1][s];
                if (nums2[j] >= cache[i][j+1][s]) {
                    cache[i][j][s] = res[s] = nums2[j];
                    generate(nums1, nums2, res, cache, i, j+1, s+1);
                }
            } else if (j == m) {
                generate(nums1, nums2, res, cache, i+1, j, s);
                cache[i][j][s] = cache[i+1][j][s];
                if (nums1[i] >= cache[i+1][j][s]) {
                    cache[i][j][s] = res[s] = nums1[i];
                    generate(nums1, nums2, res, cache, i+1, j, s+1);
                }
            } else {
                generate(nums1, nums2, res, cache, i+1, j, s);
                if (nums1[i] == nums2[j]) {
                    cache[i][j][s] = res[s] = nums1[i];
                    generate(nums1, nums2, res, cache, i+1, j, s+1);
                    generate(nums1, nums2, res, cache, i, j+1, s+1);
                    return;
                }
                if (nums1[i] >= cache[i+1][j][s]) {
                    cache[i][j][s] = res[s] = nums1[i];
                    generate(nums1, nums2, res, cache, i+1, j, s+1);
                    return;
                }
                generate(nums1, nums2, res, cache, i, j+1, s);
                if (nums2[j] >= cache[i][j+1][s]) {
                    cache[i][j][s] = res[s] = nums2[j];
                    generate(nums1, nums2, res, cache, i, j+1, s+1);
                    return;
                }
                generate(nums1, nums2, res, cache, i+1, j+1, s);
                cache[i][j][s] = cache[i+1][j+1][s];
            }
        }

        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
            int n = nums1.size(), m = nums2.size();
            vector<vector<vector<int> > > cache(n+2, vector<vector<int> > (m+2, vector<int> (k, -1)));
            vector<int> res(k, 0);
            generate(nums1, nums2, res, cache, 0, 0, 0);
            for (int s=0; s<k; s++){
                for (int i=0; i<=n; i++) {
                    for (int j=0; j<=m; j++) {
                        printf("%d ", cache[i][j][s]);
                    }
                    cout << endl;
                }
                cout << endl << endl;
            }
            return res;
        }
};


int main () {
    int num1[] = {3, 4, 6, 5}, num2[] = {1, 2, 5, 8, 3};
   // int num1[] = {6, 5}, num2[] = {8, 3};
    vector<int> nums1, nums2;
    for (int i=0; i<sizeof(num1)/sizeof(num1[0]); i++) nums1.push_back(num1[i]);
    for (int i=0; i<sizeof(num2)/sizeof(num2[0]); i++) nums2.push_back(num2[i]);
    Solution s;
    vector<int> res = s.maxNumber(nums1, nums2, 4);
    for (int e :res) printf("%d ", e);
    cout << endl;
}
