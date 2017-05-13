class Solution {

    unordered_map<string,string> ls, sl;
    int cnt;
    char intToChar (int i) {
        // nums : 0-9
        // a-z : 10 - 35
        // A-Z : 36 - 61
        i = i%62;
        if (i<10) return '0'+i;
        if (i<36) return 'a' + i-10;
        return 'A' + i-36;
    }

    string intToString (int num) {
        string str = "";
        while (num > 0) {
            str += string(1, intToChar(num%62));
            num /= 62;
        }
        return str;
    }

    public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (ls.find(longUrl) != ls.end())
            return ls[longUrl];
        string res = intToString(++cnt);
        ls[longUrl] = res;
        sl[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (sl.find(shortUrl) == sl.end()) return "";
        return sl[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

