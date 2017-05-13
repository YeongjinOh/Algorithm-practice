class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) return addStrings(num2, num1);
        int carry = 0, n = num1.size(), m = num2.size();
        for (int i=0; i<n; i++) {
            int add = i<m?num2[m-1-i]-'0':0;
            int sum = num1[n-1-i]-'0' + add + carry;
            carry = sum/10;
            num1[n-1-i] = '0' + sum%10;
        }
        if (carry) return "1" + num1;
        return num1;
    }
};
