class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {

            int n = nums.size();
            if (n<3) return false;
            vector<int> st;
            st.push_back(nums[0]);
            for (int i=1; i<n; i++) {
                if (st[0] >= nums[i]) {
                    st[0] = nums[i];
                } else if (st.size() == 2 && st[1] >= nums[i]) {
                    st[1] = nums[i];
                } else if (nums[i] > st.back()) {
                    st.push_back(nums[i]);
                }
                if (st.size() == 3) return true;
            }
            return false;
        }
};
