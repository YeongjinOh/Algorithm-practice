#include <iostream>
#include <vector>
#include <algorithm>
#define LEN 200005
using namespace std;

int gcd (int a, int b) {
    if (a<b) return gcd(b, a);
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

int gcdE (int a, int b, int& x, int& y) {
    if (a < b) return gcdE(b, a, y, x);
    if (a % b == 0) {
        x = 0; y = 1;
        return b;
    }
    int x0, y0;
    int g = gcdE(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a/b)*y0;
    return g;
}

int modulo_inverse(int a, int m) {
    int x, y;
    int g = gcdE(a,m,x,y);
    if (g != 1) {
        cout << "a and m is not coprime!!" << endl;
        return -1;
    }
       while (x < 0) { x += m; }
        return x%m;
}

// calculate x such that (a*x)%m = b
int modulo_divisor(int a, int b, int m) {
    int g = gcd(a,m);
    a/=g, b/=g, m/=g;
    // now, a and m is coprime
    return ((long long)modulo_inverse(a, m) * (long long)b)%m;
}

int main() {
    int n, m, a;
    cin >> n >> m;
    vector<bool> visit(m, false);

    ///////////////////////////////////////////////
    // m의 약수마다의 공간을 나눠야한다.
    ///////////////////////////////////////////////
    vector<int> div[LEN]; // div[i] 는 m의 약수 i의 배수들의 집합
    vector<int> factor;
    for (int i=1; i<m; i++) {
        int g = gcd(m,i);
        if (div[g].size() == 0)
            factor.push_back(g);
        div[g].push_back(i);
    }
    while (n--) {
        scanf("%d", &a);
        visit[a] = true;
        if (a) {
            int g = gcd(m,a);
            div[g].erase(find(div[g].begin(), div[g].end(), a));
        }
    }

    // dynamic array and trace
    factor.push_back(m);
    vector<int> d(factor.size(), 0), trace(factor.size(), -1);
    for (int i=factor.size()-1; i>0; i--) {
        for (int j=i-1; j>=0; j--) {
            int lg = factor[i], sm = factor[j];
            // only lg can follow sm when lg%sm == 0
            if (lg%sm == 0 && d[j] < (d[i] + div[sm].size())) {
                d[j] = d[i] + div[sm].size();
                trace[j] = i;
            }
        }
    }
    // start from max
    int start = 0;
    for (int i=1; i<d.size(); i++) if (d[i] > d[start]) start = i;
    // reconstruct trace
    vector<int> pps, sol; // prefix products of sequence
    while (start != -1) {
        pps.insert(pps.end(),div[factor[start]].begin(), div[factor[start]].end());
        start = trace[start];
    }

    //for (int i=0; i<pps.size(); i++) printf("%d ", pps[i]);
    // build solution from pps
    if (pps.size() > 0) {
        sol.push_back(pps[0]);
        for (int i=1; i<pps.size(); i++)
            sol.push_back(modulo_divisor(pps[i-1],pps[i],m));
    }
    if (!visit[0]) sol.push_back(0);

    // print solution
    printf("%d\n", sol.size());
    for (int i=0; i<sol.size(); i++) printf("%d ", sol[i]);
}
