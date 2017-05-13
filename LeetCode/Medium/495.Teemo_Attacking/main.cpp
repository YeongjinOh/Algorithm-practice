class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;
        if (timeSeries.size() == 0) return sum;
        for (int i=0; i<(int)timeSeries.size()-1; i++)
            sum += min(timeSeries[i+1] - timeSeries[i], duration);
        return sum+duration;
    }
};
