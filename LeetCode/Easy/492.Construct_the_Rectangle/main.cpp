class Solution {
public:
    int sqrt (int num) {
        if(num <= 0) return 0;
        int l = 0, r = (1<<16)-1;
        while (l<r){
            int mid = (l+r+1)/2;
            if (mid * mid <= num) l = mid;
            else r = mid -1;
        }
        return l;
    }
    vector<int> constructRectangle(int area) {
        vector<int> res;
        printf("%d", sqrt(area));
        for (int i=sqrt(area); i>=1; i--) {
            if (area%i == 0)  {
                res.push_back(area/i);
                res.push_back(i);
                return res;
            }
        }
        return res;
    }
};
