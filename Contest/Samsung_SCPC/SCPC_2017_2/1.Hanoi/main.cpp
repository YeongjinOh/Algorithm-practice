/*
   You should use the statndard input/output

   in order to receive a score properly.

   Do not use file input and output

   Please be very careful.
   */

#include <iostream>
#include <vector>

using namespace std;

char prev(char c) {
    return c=='A'? 'C' : c-1;
}
char next(char c) {
    return c=='C'? 'A' : c+1;
}

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

        bool Answer = true;
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
           */
        /////////////////////////////////////////////////////////////////////////////////////////////

        int n;
        string hanoi;
        cin >> n >> hanoi;
        char from='A', to='B';
        for (int i=n-1; i>=0; i--) {
//            printf("cur:%c from:%c to:%c\n", hanoi[i], from, to);
            if (next(from) == to) {
                if (hanoi[i] == from) {
                    to = next(to);
                } else if (hanoi[i] == to) {
                    from = prev(from);
                } else {
                    Answer = false;
                    break;
                }
            } else {
                if (hanoi[i] == next(from)) {
                    swap(from, to);
                }
            }
        }

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        if (Answer)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
