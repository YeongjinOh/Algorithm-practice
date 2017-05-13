class Solution {
    public:
        void dfs(vector<vector<int> > &res, vector<int> &cur, vector<int> &nums, int pos) {
            res.push_back(cur);
            // in this case, we don't need hash table to check duplicate numbers
            // (Since nums are sorted)
            // unordered_set<int> hs;
            for (int i=pos; i<nums.size(); i++) {
                //	if (hs.find(nums[i]) == hs.end()) {
                if (i == pos || nums[i] != nums[i-1]) {
                    cur.push_back(nums[i]);
                    dfs(res,cur,nums,i+1);
                    cur.pop_back();
                    //		hs.insert(nums[i]);
                }
            }
            }
            vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                vector<vector<int> > res;
                vector<int> cur;
                sort(nums.begin(), nums.end());
                dfs(res,cur,nums,0);
                return res;
            }
        };
