/*
   You should use the statndard input/output

   in order to receive a score properly.

   Do not use file input and output

   Please be very careful.
   */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
       */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {

        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
           */
        /////////////////////////////////////////////////////////////////////////////////////////////
        string str;
        cin >> str;
        int n = str.size();
        stack<pair<char,int> > st;
        vector<bool> res(n, false);
        for (int i=0; i<n; i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(make_pair(str[i], i));
            } else if (!st.empty()) {
                char prev = st.top().first;
                if ((prev== '(' && str[i] == ')')
                    || (prev == '[' && str[i] == ']')
                    || (prev == '{' && str[i] == '}')) {
                    res[i] = res[st.top().second] = true;
                    st.pop();
                } else {
                    while( !st.empty() ) st.pop();
                }
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (res[i]) {
                cnt++;
                Answer = max(Answer, cnt);
            } else {
                cnt = 0;
            }
        }
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
