#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int n, k, l, r, a, b;

ll get (ll group, ll n) {
    ll res;
    ll q = n/group, r = n%group;
    res = a*group + b*(r*q*q + (group-r)*(q-1)*(q-1));
    return res;
}

ll minll (ll a, ll b) { return a>b?b:a; }
int main() {
    scanf("%d%d%d", &n, &a, &b);
    string str;
    cin >> str;
    ll adult = 0;
    for (int i=0; i<str.size(); i++)
        if (str[i] == '1')
            adult++;
    ll res = get(1, n);
    for (int i=2; i<=adult; i++)
        res = minll(res, get(i, n));
    cout << res << endl;
    return 0;
}
