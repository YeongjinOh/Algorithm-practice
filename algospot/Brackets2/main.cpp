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
        for (int i=0; i<str.size(); i++) {
            char c = str[i];
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else {
                if (st.size() == 0) {
                    success = false;
                    break;
                }
                char top = st.top();
                if ( (c==')' && top != '(') || (c==']' && top!='[') || (c=='}' && top!='{') )  {
                    success = false;
                    break;
                }
                st.pop();
            }
        }
        if (success && st.size() == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
