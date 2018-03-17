#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // chose k numbers from nums
        // Time: O(n)
        void chooseNumbers(vector<int>& nums, vector<int>& st, int k) {
            int n = nums.size();
            for (int i=0; i<n; i++) {
                while (!st.empty() && st.back() < nums[i] && n-i + st.size() > k) {
                    st.pop_back();
                }
                st.push_back(nums[i]);
            }
        }
        // Time: O(k(n+m))
        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<int> best(k,0);
            for (int s=0; s<=k; s++) {
                // s = # of elements chose from nums1
                // k-s = " from nums2
                if (s > nums1.size() || k-s > nums2.size()) continue;
                vector<int> p1, p2;
                chooseNumbers(nums1, p1, s);
                chooseNumbers(nums2, p2, k-s);
                int i=0, j=0;
                vector<int> cur(k,0);
                while (i+j < k) {
                    bool useP1 = false;
                    if (i<s && j<k-s && p1[i] == p2[j]) {
                        int off = 1;
                        while (i+off < s && j+off < k-s && p1[i+off] == p2[j+off] && p1[i+off] >= p1[i]) { off++; }
                        if (i+off < s && j+off < k-s) {
                            useP1 = (p1[i+off] > p2[j+off]);
                        } else {
                            useP1 = (i+off < s && p1[i+off] >= p1[i]);
                        }
                    } else {
                        useP1 = i<s &&  (j == k-s || p1[i] > p2[j]);
                    }
                    if (useP1) {
                        cur[i+j] = p1[i];
                        i++;
                    } else {
                        cur[i+j] = p2[j];
                        j++;
                    }
                }
                bool bigger = false;
                for (int i=0; i<k; i++) {
                    if (bigger) {
                        best[i] = cur[i];
                        continue;
                    } else if (best[i] < cur[i]) {
                        bigger = true;
                        best[i] = cur[i];
                    } else if (best[i] > cur[i]) {
                        break;
                    }
                }
            }
            return best;
        }

        // 한번에 하는 게 가능할 것 같다.
        // incomplete.
        // need to try this method
        vector<int> maxNumber2(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<int> best;
            int i=0, j=0, n=nums1.size(), m=nums2.size();
            while (i+j < n+m) {
                bool useP1 = false;
                if (i<n && j<m && nums1[i] == nums2[j]) {
                    int off = 1;
                    while (i+off < n && j+off < m && nums1[i+off] == nums2[j+off] && nums1[i+off] >= nums1[i]) { off++; }
                    if (i+off < n && j+off < m) {
                        useP1 = (nums1[i+off] > nums2[j+off]);
                    } else {
                        useP1 = (i+off < n && nums1[i+off] >= nums1[i]);
                    }
                } else {
                    useP1 = i<n &&  (j == m || nums1[i] > nums2[j]);
                }
                int cur;
                if (useP1) {
                    cur = nums1[i++];
                } else {
                    cur = nums2[j++];
                }
                while(!best.empty() && best.back() < cur && (n-i) + (m-j) + 1 >= k) {
                    best.pop_back();
                }
                best.push_back(cur);
            }
            while (best.size() > k) { best.pop_back(); }
            return best;
        }
};


int main () {
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i=0; i<n; i++) cin >> nums1[i];
    for (int i=0; i<n; i++) cin >> nums2[i];
    int k = n;
    Solution s;
    vector<int> res = s.maxNumber2(nums1, nums2, k);
    for (int e :res) printf("%d ", e);
    cout << endl;
}
