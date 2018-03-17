class Solution {
    public:
        // O(n)
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq;
            vector<int> res;
            for (int i=0; i<nums.size(); i++) {
                if (!dq.empty() && i-dq.front() == k) dq.pop_front();
                while (!dq.empty() && nums[dq.back()] <= nums[i]) { dq.pop_back(); }
                dq.push_back(i);
                if (i >= k-1)
                    res.push_back(nums[dq.front()]);
            }
            return res;
        }

        // O(nlogk)
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            multiset<int> si;
            vector<int> res;
            for (int i=0; i<nums.size(); i++) {
                si.insert(nums[i]);
                if (i >= k)
                    si.erase(si.find(nums[i-k]));
                if (i >= k-1) {
                    res.push_back(*si.rbegin());
                }
            }
            return res;
        }
};
