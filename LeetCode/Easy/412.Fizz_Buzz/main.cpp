class Solution {
public:

    string intToString (int num) {
        string strs[10] = {"0","1","2","3","4","5","6","7","8","9"};
        string res = "";
        while(num > 0) {
            res = strs[num%10] + res;
            num /= 10;
        }
        return res;
    }
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i=1; i<=n; i++) {
            if (i%3 != 0 && i%5 != 0)
                res.push_back(intToString(i));
            else {
                string word = "";
                if (i%3 == 0) word += "Fizz";
                if (i%5 == 0) word += "Buzz";
                res.push_back(word);
            }

        }
        return res;
    }
};
