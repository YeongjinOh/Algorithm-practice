#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int C;
string str;
int main() {
    cin >> C;
    while (C--) {
        cin >> str;
        stack<char> st;
        bool success = true;
        string opening("([{"), closing(")]}");
        for (int i=0; i<str.size(); i++) {
            char c = str[i];
            if (opening.find(c) != -1)
                st.push(c);
            else {
                if (st.empty()) {
                    success = false;
                    break;
                }
                char top = st.top();
                if (opening.find(top) != closing.find(c)) {
                    success = false;
                    break;
                }
                st.pop();
            }
        }
        if (success && st.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
