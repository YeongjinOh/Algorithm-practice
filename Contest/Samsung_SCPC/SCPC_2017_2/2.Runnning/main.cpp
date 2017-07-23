/*
   You should use the statndard input/output

   in order to receive a score properly.

   Do not use file input and output

   Please be very careful.
   */

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll ans;

// ax + by = gcd(a,b)
ll gcdExtended(ll a, ll b, ll &x, ll &y) {
    if (b > a) return gcdExtended(b,a,y,x);
    if (a%b == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x0, y0;
    ll g = gcdExtended(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a/b) * y0;
    return g;
}

void getCommonLinearCombination(ll a1, ll b1, ll a2, ll b2, ll &a3, ll &b3) {
    ll x, y;
    ll g = gcdExtended(b1, b2, x, y);
//    printf("(%d)*(%d) + (%d)*(%d) = %d\n", b1, x, b2, y, g);
    // a1*x + a2*y = g
    x = x*(a2-a1)/g;
    y = y*(a1-a2)/g;
    // now, we have a1*x - a2*y = b2 - b1
    a3 = b1*x+a1;
    printf("%d = %d\n", b1*x+a1, b2*y+a2);
    b3 = b1*b2/g;
    // now, t = b3*k + a3
    a3 = ((a3%b3)+b3)%b3;
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
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
           */
        /////////////////////////////////////////////////////////////////////////////////////////////
        int n;
        cin >> n;
        vector<ll> s(n), l(n), d(l), a(n), b(n);
        for (int i=0; i<n; i++) {
            cin >> s[i] >> l[i] >> d[i];
            // s*a + l*b = g : a is time, b means how many circle
            ll g = gcdExtended(s[i], l[i], a[i], b[i]);
            a[i] = -1*a[i]*d[i]/g;
            b[i] = l[i]/g;
            a[i] = ((a[i]%b[i])+b[i])%b[i];
            printf("t = %d * k + %d\n", b[i], a[i]);
        }
        ll a1 = a[0], b1 = b[0];
        for (int i=1; i<n; i++) {
            ll a2 = a[i], b2 = b[i], a3, b3;
            getCommonLinearCombination(a1, b1, a2, b2, a3, b3);
            printf("%d*k+%d %d*k+%d -> %d*k+%d\n", b1, a1, b2, a2, b3, a3);
            a1 = a3; b1 = b3;
        }
        ll ans = (a1==0?b1:a1);
       // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << ans << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
