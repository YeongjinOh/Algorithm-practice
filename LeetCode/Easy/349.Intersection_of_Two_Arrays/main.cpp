class Solution {
public:
	// using sort
	// Time : O(nlogn)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++; j++;
                while (i < nums1.size() && nums1[i-1] == nums1[i]) { i++; }
                while (j < nums2.size() && nums2[j-1] == nums2[j]) { j++; }
            } else if (nums1[i] < nums2[j]) i++;
            else j++;
        }
        return res;
    }

	// using hash
	// Time : O(m+n) * hash access time
    vector<int> intersectionUsingHash(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, bool> candidate;
        for (int i=0; i<nums1.size(); i++) candidate[nums1[i]] = true;
        for (int i=0; i<nums2.size(); i++) {
            if (candidate[nums2[i]]) {
                res.push_back(nums2[i]);
                candidate[nums2[i]] = false;
            }
        }
        return res;
    }
};
