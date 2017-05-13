class Solution {
public:
    int hammingDistance(int x, int y) {
        int xXORy = x^y;
        int res = 0;
        while (xXORy>0) {
            res += xXORy%2;
            xXORy /= 2;
        }
        return res;
    }
};
