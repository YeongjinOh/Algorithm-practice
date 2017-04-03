#include <iostream>
bool digit[10];
using namespace std;

void setDigit (int n) {
    int d = n;
    while (d > 0) {
        digit[d%10] = true;
        d /= 10;
    }
}

void solve (int n) {
    if (n==0) {
        cout << "INSOMNIA";
        return;
    }
    int tmp = n;
    while (true) {
        setDigit(tmp);
        bool check = true;
        for (int i=0; i<10; i++) check &= digit[i];
        if (check) break;
        tmp += n;
    }
    cout << tmp;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        cout << "Case #" << i << ": ";
        // reset digit
        for (int j=0; j<10; j++) digit[j] = false;
        solve(n);
        cout << endl;
    }
    return 0;
}
