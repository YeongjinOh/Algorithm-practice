class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int,int> m;
        stack<int> s;
        for (int i=0; i<nums.size(); i++) {
            while (!s.empty() && s.top() < nums[i]) {
                int cur = s.top(); s.pop();
                m[cur] = nums[i];
            }
            s.push(nums[i]);
        }
        vector<int> res;
        for (int i=0; i<findNums.size(); i++) {
            if (m[findNums[i]]) res.push_back(m[findNums[i]]);
            else res.push_back(-1);
        }
        return res;
    }
};
