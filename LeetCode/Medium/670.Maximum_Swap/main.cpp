class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        while (num) {
            digits.push_back(num%10);
            num /= 10;
        }
        bool done = false;
        for (int i=digits.size()-1; i>=0; i--) {
            int idx = i;
            for (int j=0; j<i && !done; j++) {
                if (digits[idx] < digits[j]) {
                    idx = j;
                }
            }
            if (idx != i) {
                swap(digits[i], digits[idx]);
                done = true;
            }
            num = num * 10 + digits[i];
        }
        return num;
    }
};
