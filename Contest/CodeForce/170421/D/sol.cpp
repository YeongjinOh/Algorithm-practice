#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<set>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const double pi=acos(-1);
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=Next[i])
#define clr(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
#define putk() putchar(' ')
ld eps=1e-9;
ll pp=1000000007;
ll mo(ll a,ll pp){if(a>=0 && a<pp)return a;a%=pp;if(a<0)a+=pp;return a;}
ll powmod(ll a,ll b,ll pp){ll ans=1;for(;b;b>>=1,a=mo(a*a,pp))if(b&1)ans=mo(ans*a,pp);return ans;}
ll gcd(ll a,ll b){return (!b)?a:gcd(b,a%b);}
ll read(){
    ll ans=0;
    char last=' ',ch=getchar();
    while(ch<'0' || ch>'9')last=ch,ch=getchar();
    while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
    if(last=='-')ans=-ans;
    return ans;
}
/*
void put(ll a){
    if(a<0)putchar('-'),a=-a;
    int top=0,q[20];
    while(a)q[++top]=a%10,a/=10;
    top=max(top,1);
    while(top--)putchar('0'+q[top+1]);
}
*/
//head
#define N 110000
int n,ans[N];
struct node{
    int x,y,id;
}a[N];
ll s1,s2,t1,t2;
bool cmp(node a,node b){
    return a.x>b.x;
}
/*
bool operator <(node a,node b){
    return (a.y<b.y)||(a.y==b.y && a.x<b.x);
}
bool operator >(node a,node b){
    return (a.y>b.y)||(a.y==b.y && a.x>b.x);
}

set<node>q;

set<node>::iterator it;
*/
int main(){
    //	freopen("1.in","r",stdin);
    n=read();
    rep(i,1,n)a[i].x=read(),s1+=a[i].x;
    rep(i,1,n)a[i].y=read(),s2+=a[i].y;
    rep(i,1,n)a[i].id=i;
    sort(a+1,a+n+1,cmp);
    int lim=n/2+1;
    for(int i=1+n%2;i<=n;i+=2)
        if(a[i].y>a[i+1].y)
            ans[a[i].id]=1;
        else ans[a[i+1].id]=1;
    rep(i,1,n)
        if(!ans[a[i].id]){
            ans[a[i].id]=1;
            break;
        }
    cout<<lim<<endl;
    rep(i,1,n)
        if(ans[i])printf("%d ",i);
    return 0;
}
