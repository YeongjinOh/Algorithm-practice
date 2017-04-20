#include <iostream>
using namespace std;

int gcd (int a, int b) {
    if (b > a) return gcd(b,a);
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

// ax + by = gcd(a,b)
int gcdExtended(int a, int b, int *x, int *y) {
    if (b > a) return gcdExtended(b,a,y,x);
    if (a%b == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x0, y0;
    int g = gcdExtended(b, a%b, &x0, &y0);
    *x = y0;
    *y = x0 - (a/b) * y0;
    return g;
}

int main() {
    cout << "insert a, b:";
    int a, b;
    cin >> a >> b;
    cout << "gcd(a,b) = " << gcd(a,b) << endl;
    int x, y;
    int g = gcdExtended(a,b,&x,&y);
    printf("ax+by=g : %d*%d+%d*%d=%d\n", a,x,b,y,g);
}
