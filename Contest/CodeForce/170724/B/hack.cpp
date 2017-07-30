#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 5e18
#include <stdlib.h>
char c[100005], d[100005], h[100005];
int m[30],n,t=-100,ff=0,de,he;
int so()
{
    gets(h);
    ff=1;
    de=strlen(h)-strlen(d);
    he = 0;
    for (int j=0; j<= strlen(d)-1; j++)
    {
        if(d[j] == '?')
        {
            if(m[h[he]-'a'+1] != 1)
            {
                printf("NO\n");
                return 0;
            }
        }
        else if(d[j] =='*')
        {
            de++;
            he--;
            while(de--)
            {
                he++;
                if(m[h[he]-'a'+1]!=0)
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }
        else if(d[j] !=h[he])
        {
            printf("NO\n");
            return 0;
        }
        he++;
    }
    if(ff) printf("YES\n");

    return 0;
}
int main()
{
    gets(c);
    gets(d);
    memset(m,0,sizeof(m));
    for (int i=0; i<=strlen(c)-1; i++)
    {
        m[c[i]-'a'+1]=1;
    }
    scanf("%d", &n);
    getchar();
    for (int i=1; i<=n; i++)
    {
        so();
    }
    return 0;
}
