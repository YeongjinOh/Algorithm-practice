class Solution {
public:
    int findComplement(int num) {
        int base = 0, res = 0;
        while(num>0) {
            res += (1-num%2)<<base++;
            num/=2;
        }
        return res;
    }
};
