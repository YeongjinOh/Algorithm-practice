class Solution {
public:
    void buildComb (int idx, int sum, int curCnt, int goalCnt, int ub, vector<int>& set, vector<int>& res) {
        if (sum >= ub) return;
        if (goalCnt == curCnt) {
            res.push_back(sum);
            return;
        }
        if (idx >= set.size()) return;
        buildComb(idx+1, sum + set[idx], curCnt+1, goalCnt, ub, set, res);
        buildComb(idx+1, sum, curCnt, goalCnt, ub, set, res);
    }
    vector<string> readBinaryWatch(int num) {
        vector<int> mins, hours;
        vector<string> res;
        for (int i=1; i<=8; i*=2) hours.push_back(i);
        for (int i=1; i<=32; i*=2) mins.push_back(i);
        for (int i=0; i<=num; i++) {
            vector<int> hourCombs, minCombs;
            buildComb(0,0,0,i,12,hours,hourCombs);
            buildComb(0,0,0,num-i,60,mins,minCombs);
            for (int j=0; j<hourCombs.size(); j++) {
                for (int k=0; k<minCombs.size(); k++) {
                    string time = std::to_string(hourCombs[j]) + ":";
                    time += minCombs[k] < 10? "0": "";
                    time += std::to_string(minCombs[k]);
                    res.push_back(time);
                }
            }
        }
        return res;
    }
};
