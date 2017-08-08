#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define INV "invalid"
bool isSmall (char c) {
    return c >= 'a' && c <= 'z';
}

string solution(string sentence) {
    string answer = "";
    for (int i=0; i<sentence.size(); i++)
        if (sentence[i] == ' ')
            return INV;
    vector<int> cnt(26, 0), last(26, -1);
    for (int i=0; i<sentence.size(); i++) {
        if (isSmall(sentence[i])) {
            cnt[sentence[i]-'a']++;
            last[sentence[i]-'a'] = i;
        }
    }
    vector<bool> space(sentence.size()+5, false);
    vector<bool> used(26, false);
    int lastIdx = -1;
    for (int i=2; i<sentence.size(); i++)
        if (isSmall(sentence[i-2]) && isSmall(sentence[i-1]) && isSmall(sentence[i])) return INV;
    for (int i=1; i<sentence.size(); i++)
        if (isSmall(sentence[i-1]) && isSmall(sentence[i])) {
            if (sentence[i-1] == sentence[i] || cnt[sentence[i-1]-'a'] != 2 || cnt[sentence[i]-'a'] != 2) return INV;
        }
    for (int i=0; i<sentence.size(); i++) {
        if (isSmall(sentence[i])) {
            char cur = sentence[i];
            if (used[cur-'a'])
                return INV;
            used[cur-'a'] = true;
            if (cnt[cur-'a'] == 1) {
                if (i == 0 || i == sentence.size()-1) return INV;
                if (lastIdx >= i-1 || isSmall(sentence[i-1]) || isSmall(sentence[i+1])) return INV;
                lastIdx = i+1;
                space[i-1] = true;
                i = i+1;
                space[i+2] = true;
            }
            else if (cnt[cur-'a'] == 2) {
                bool hasSmall = false;
                for (int j=i+1; j<last[cur-'a']; j++) {
                    if (isSmall(sentence[j])) {
                        hasSmall = true;
                        break;
                    }
                }
                if (hasSmall) {
                    char inner = sentence[i+2];
                    if (!isSmall(inner) || used[inner-'a'])
                        return INV;
                    used[inner-'a'] = true;
                    if ((last[cur-'a'] - i)%2 != 0 || last[cur-'a'] - last[inner-'a'] != 2) return INV;
                    for (int j=i+1; j<last[inner-'a']; j+=2) {
                        if (isSmall(sentence[j]) || sentence[j+1] != inner) {
                            return INV;
                        }
                    }
                    if (isSmall(sentence[last[inner-'a']+1])) return INV;
                }
                space[i] = true;
                i = last[cur-'a'];
                lastIdx = i-1;
                space[i+1] = true;
            }
            else {
                if (i == 0 || i == sentence.size()-1 || isSmall(sentence[i-1])) return INV;
                if (i-1 == lastIdx) return INV;
                for (int j=i; j<=last[cur-'a']; j+=2) {
                    if (sentence[j] != cur || isSmall(sentence[j+1]))
                        return INV;
                }
                space[i-1] = true;
                i = last[cur-'a']+1;
                lastIdx = i;
                space[i+1] = true;
            }
        }
    }
    bool lastSpace = true;
    for (int i=0; i<sentence.size(); i++) {
        if (!lastSpace && space[i]) {
            answer += " ";
            lastSpace = true;
        }
        if (!isSmall(sentence[i])) {
            answer += sentence[i];
            lastSpace = false;
        }
    }
    if (answer.back() == ' ')
        return answer.substr(0, answer.size()-1);
    return answer;
}

int main () {
    string str;
    cin >> str;
    cout << solution(str) << endl;
    return 0;
}
