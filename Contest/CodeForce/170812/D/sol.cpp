#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long LL;
typedef unsigned long long LLU;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
const bool print=false;

const int N=1000*1007;
const int D=1000*1000;
const long long MOD=1000*1000*1000+7;

int n;

long long nad[N];

long long res;

long long pot[N];

long long f(long long v)
{
    if (!v)
        return 0;
    return (pot[v-1]*v)%MOD;
}

int main()
{
    pot[0]=1;
    for (int i=1; i<=D; i++)
        pot[i]=(pot[i-1]*2)%MOD;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        int x;
        scanf("%d", &x);
        nad[x]++;
    }
    for (int i=1; i<=D; i++)
        for (int j=i*2; j<=D; j+=i)
            nad[i]+=nad[j];
    for (int i=1; i<=D; i++)
    {
        nad[i]=f(nad[i]);
    }
    for (int i=D; i>1; i--)
    {
        for (int j=2*i; j<=D; j+=i)
            nad[i]=(nad[i]+MOD-nad[j])%MOD;
        //nad[i]=(nad[i]-1+MOD)%MOD;
        res+=nad[i]*i;
        res%=MOD;
    }
    printf("%lld\n", res);
    return 0;
}
