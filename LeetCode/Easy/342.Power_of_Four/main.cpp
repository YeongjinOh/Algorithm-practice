class Solution {
public:
    bool isPowerOfFour(int num) {
        return ((num & (num-1)) == 0) && ((0x55555555 & num) != 0);
    }
};
