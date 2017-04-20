#include <iostream>
using namespace std;

// Extended Euler's GCD
int gcd (int a, int b, int& x, int& y) {
    if (a < b) return gcd(b,a,y,x);
    if (a % b == 0) {
        x = 0; y = 1;
        return b;
    }
    int x0, y0;
    int g = gcd(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a/b)*y0;
    return g;
}

// 1) Naive Method, O(m)
int modulo_inverse (int a, int m) {
    for (int i=1; i<m; i++) {
        if (a*i%m == 1) return i;
    }
    return 0;
}

// 2) Extended Euler’s GCD algorithm, O(Log m) [Works when a and m are coprime]
int fast_modulo_inverse (int a, int m) {
    int x, y;
    if (gcd(a,m,x,y) != 1) {
        cout << "a and m should be coprime!!" << endl;
        return -1;
    }
    while(x<0) { x+=m; }
    return x%m;
}

int pow_modulo (int a, int n, int m) {
    if (n == 0) return 1;
    int res = pow_modulo(a, n/2, m);
    return (res * res * (n%2==1?a:1))%m;
}

// 3) Fermat’s Little theorem, O(Log m) [Works when ‘m’ is prime]
int fermat_modulo_inverse (int a, int p) {
    return pow_modulo(a, p-2, p)%p;
}

int main() {

    cout << "type a, m : " << endl;
    int a, m;
    cin >> a >> m;
    printf("a^-1 (mod m) : \n");
    printf("1) Naive method : %d\n", modulo_inverse(a, m));
    printf("2) Extended Euler's GCD : %d\n", fast_modulo_inverse(a, m));
    printf("3) Fermat's little Theorem : %d\n", fermat_modulo_inverse(a,m));
    return 0;
}
