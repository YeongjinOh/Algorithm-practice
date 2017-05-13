class Solution {
public:
    int countSegments(string s) {
    	int res = 0;
	    bool isCounting = false;
	    for (int i=0; i<s.size(); i++) {
    	    if (s[i] == ' ') {
                isCounting = false;
		    } else if (!isCounting) {
    			res++;
                isCounting = true;
		    }
	    }
        return res;
    }
};
