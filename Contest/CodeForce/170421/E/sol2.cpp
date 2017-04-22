#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) (int)x.size()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef vector<pii> vpii;

template<typename T>
T getint() {
    T x=0,p=1;
    char ch;
    do{ch=getchar();}while(ch <= ' ');
    if(ch=='-')p=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*p;
}


const int maxn=(int)1e6+10;
const int inf=(int)1e9+5;
const int mod=(int)1e9+7;
const ll llinf=(ll)1e18+5;

vector<int> y[maxn];
vector<int> x[maxn];

int n;

set<int> s;
vi ans;
int pos[maxn];
pii t[4*maxn];

void upd(int v,int idx,int val,int tl,int tr){
    if(tl==tr){
        t[v]=mp(val,idx);
        return;
    }
    int tm=(tl+tr)/2;
    if(idx<=tm)upd(v+v,idx,val,tl,tm);
    else upd(v+v+1,idx,val,tm+1,tr);
    t[v]=max(t[v+v],t[v+v+1]);
}

pii getmax(int v,int l,int r,int tl,int tr){
    if(l>r||r<tl||l>tr)return mp(-inf,-1);
    if(l<=tl&&tr<=r){
        return t[v];
    }
    int tm=(tl+tr)/2;
    return max(getmax(v+v,l,r,tl,tm),getmax(v+v+1,l,r,tm+1,tr));
}

void dfs(int v){
    s.erase(v);
    upd(1,v,-inf,1,n);
    for(int z:x[v]){
        if(s.count(z))dfs(z);
    }
    for(int j:y[v]){
        while(true){
            auto z=getmax(1,1,j,1,n);
            if(z.fi>=v)dfs(z.se);
            else break;
        }
    }
    ans.pb(v);
}

int main() {

  //  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    n=getint<int>();
    rep(i,1,n+1)pos[i]=n+i;
    rep(i,1,n+1){
        int j;
        j=getint<int>();
        if(j==-1)j=n+1;
        else pos[j]=i-1;
        y[i].pb(j-1);
        if(j!=n+1)x[j].pb(i);
        s.insert(i);
    }
    cout << "pos "<< endl;
    for (int i=1; i<=n; i++) printf("%d ", pos[i]);
    cout << endl << "x : " << endl;
    for (int i=1; i<=n; i++) {
        printf("%d : ", i);
        for (int j=0; j<x[i].size(); j++) printf("%d ", x[i][j]);
        cout << endl;
    }
    cout << endl << "y : " << endl;
    for (int i=1; i<=n; i++) {
        printf("%d : ", i);
        for (int j=0; j<y[i].size(); j++) printf("%d ", y[i][j]);
        cout << endl;
    }
    rep(i,1,n+1){
        upd(1,i,pos[i],1,n);
    }
    for (int i=1; i<=2*n; i++)
        printf("(%d,%d)\n", t[i].fi, t[i].se);
    rep(i,1,n+1){
        if(s.count(i)){
            dfs(i);
        }
    }
    vi val(n);
    rep(i,0,n)val[ans[i]-1]=i+1;
    rep(i,0,n)printf("%d ",val[i]);
    return 0;
}
