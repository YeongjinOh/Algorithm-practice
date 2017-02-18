#include <iostream>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

class Solution {
	public:
		bool wordPattern(string pattern, string str) {

			map<char, int> p2i;
			map<string, int> w2i;
			istringstream in(str);
			int i = 0, n = pattern.size();
			for (string word; in >> word; ++i) {
				if (i == n || p2i[pattern[i]] != w2i[word])
					return false;
				p2i[pattern[i]] = w2i[word] = i + 1;
			}
			return i == n;
		}
};

int main() {
	Solution s;
	cout << s.wordPattern("abba", "cat dog dog cat") << endl;
	cout << s.wordPattern("abba", "cat cat dog cat") << endl;
	cout << s.wordPattern("abba", "cat cat cat cat") << endl;
	cout << s.wordPattern("abba", "cat dog dog cat dog") << endl;
	cout << s.wordPattern("aaab", "catdogdogat") << endl;
}
