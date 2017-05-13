class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        priority_queue<pair<int, int> > pq;
        for (int i=0; i<nums.size(); i++) pq.push(make_pair(nums[i],i));
        string medals[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i=0; !pq.empty(); i++) {
            if (i<3)
                res[pq.top().second] = medals[i];
            else
                res[pq.top().second] = std::to_string(i+1);
            pq.pop();
        }
        return res;
    }
};
