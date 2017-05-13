class Solution {
    public:
        ////////////////////////////////////////////////////////
        // solution 1. back tracking
        // inefficient since it requires set<vector<int> > type
        ////////////////////////////////////////////////////////
        void backtrack(set<vector<int> > &s, vector<int> incSubseq, vector<int> &nums, int cur) {
            if (cur == nums.size()) {
                if (incSubseq.size() >= 2)
                    s.insert(incSubseq);
                return;
            }
            backtrack(s, incSubseq, nums, cur+1);
            if (incSubseq.size() == 0 || incSubseq.back() <= nums[cur]) {
                incSubseq.push_back(nums[cur]);
                backtrack(s, incSubseq, nums, cur+1);
            }
        }

        vector<vector<int>> findSubsequences(vector<int>& nums) {
            vector<vector<int> > res;
            set<vector<int> > s;
            backtrack(s, vector<int>(), nums, 0);
            for (set<vector<int> >::iterator it = s.begin(); it != s.end(); it++)
                res.push_back(*it);
            return res;
        }

        ////////////////////////////////////////////////////////
        // solution 2. dfs
        // more efficient
        ////////////////////////////////////////////////////////
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> seq;
            dfs(res, seq, nums, 0);
            return res;
        }

        void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
            if(seq.size() > 1) res.push_back(seq);
            unordered_set<int> hash;
            for(int i = pos; i < nums.size(); ++i) {
                if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
                    seq.push_back(nums[i]);
                    dfs(res, seq, nums, i + 1);
                    seq.pop_back();
                    hash.insert(nums[i]);
                }
            }
        }

};
