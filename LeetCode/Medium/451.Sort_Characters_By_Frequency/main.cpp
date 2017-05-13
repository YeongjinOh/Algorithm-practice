class Solution {
    public:
        string frequencySort(string s) {
            unordered_map <char, int> cnt;
            for (int i=0; i<s.size(); i++) {
                cnt[s[i]]++;
            }
            vector<pair<int,char> > freqAndChars;
            for (unordered_map<char,int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
                char c = it->first;
                int freq = it->second;
                freqAndChars.push_back(make_pair(freq,c));
            }
            string res = "";
            sort(freqAndChars.begin(), freqAndChars.end());
            for (int i=freqAndChars.size()-1; i>=0; i--) {
                int freq = freqAndChars[i].first;
                char c = freqAndChars[i].second;
                res += string(freq,c);
            }
            return res;
        }
};
