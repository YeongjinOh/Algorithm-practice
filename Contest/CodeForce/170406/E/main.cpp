#include <iostream>
#include <cstring>
using namespace std;
int main() {

    string str;
    cin >> str;
    int m;
    cin >> m;

    int k = 1;
    for (int i=1; i<str.size(); i++)
        k = (10*k)%m;

    long long r = str[0]-'0';
    for (int i=1; i<str.size(); i++) {
        r = ((r*10)+(str[i]-'0'))%m;
    }
    long long res = r;
    for (int i=0; i<str.size()-1; i++) {
        int frt = str[i]-'0';
        r = (r + m - (k*frt)%m)%m;
        r = ((r*10)+(str[i]-'0'))%m;
        if (str[i+1] > 0 && res > r)
            res = r;
    }
    cout << res << endl;
}
