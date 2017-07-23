#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <cassert>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 55;

ld p[maxn];
ld U;
int n, k;

bool can(ld th)
{
    ld need = 0;
    for (int i = 0; i < n; i++) need += max((ld)0, th - p[i]);
    return need <= U;
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d: ", T);

        scanf("%d%d", &n, &k);
        double dU;
        scanf("%lf", &dU);
        U = dU;
        for (int i = 0; i < n; i++)
        {
            double x;
            scanf("%lf", &x);
            p[i] = x;
        }
        ld l = 0;
        ld r = 1;
        for (int IT = 0; IT < 100; IT++)
        {
            ld m = (l + r) / 2;
            if (can(m)) l = m;
            else r = m;
        }
        ld answer = 1;
        for (int i = 0; i < n; i++) answer *= max(p[i], l);
        printf("%.20f\n", (double)answer);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
