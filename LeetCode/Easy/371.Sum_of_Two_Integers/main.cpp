class Solution {
public:
    int getSum(int a, int b) {
        int mask = a&b;
        int res = a|b;
        if (mask == 0) return res;
        res ^= mask;
        return getSum(mask<<1,res);
    }
};
