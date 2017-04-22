#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const double pi=acos(-1);
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=nxt[i])
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
void put(ll a){
	if(a<0)putchar('-'),a=-a;
	int top=0,q[20];
	while(a)q[++top]=a%10,a/=10;
	top=max(top,1);
	while(top--)putchar('0'+q[top+1]);
}
//head
#define N 10000005
int n,head[N],v[N*4],nxt[N*4],lson[N],rson[N],du[N],num,nn,a[N/10],root;
bool b[N/10];
void add(int x,int y){
	if(!x || !y)return;
//	cout<<x<<" "<<y<<endl;
	v[++num]=y;nxt[num]=head[x];head[x]=num;du[y]++;
}
void build(int &u,int v,int l,int r,int x){
	if(l==r){
		u=l;
		return;
	}
	u=++nn;
	lson[u]=lson[v];
	rson[u]=rson[v];
	int mid=(l+r)/2;
	if(x<=mid)build(lson[u],lson[v],l,mid,x);
	else build(rson[u],rson[v],mid+1,r,x);
	add(lson[u],u);
	add(rson[u],u);
}
void work(int u,int l,int r,int x,int y,int t){
	if(x<=l && y>=r){
		add(u,t);
		return;
	}
	if(x>r || y<l || u==0)return;
	int mid=(l+r)/2;
	work(lson[u],l,mid,x,y,t);
	work(rson[u],mid+1,r,x,y,t);
}
void work(int x,int y,int t){
	if(t<=y && t>=x){
		if(x<t)work(root,1,n,x,t-1,t);
		if(t<y)work(root,1,n,t+1,y,t);
	}
	else work(root,1,n,x,y,t);
}
int main(){
//	freopen("1.in","r",stdin);
	n=read();
	nn=n;
	rep(i,1,n){
		a[i]=read();
		if(a[i]!=-1)b[a[i]]=1;
	}
	root=0;
	rep(i,1,n)
		if(b[i]==0)build(root,root,1,n,i);
	per(i,n,1){
		if(a[i]==-1)work(1,n,i);
		else work(1,a[i],i);
		if(a[i]!=-1){
			build(root,root,1,n,a[i]);
			add(i,a[i]);
		}
	}
	int t=0,w=0;
	rep(i,1,nn)
		if(du[i]==0)lson[++w]=i;
	while(t<w){
		int u=lson[++t];
		for(int i=head[u];i;i=nxt[i]){
			int t=v[i];
			du[t]--;
			if(!du[t])lson[++w]=v[i];
		}
	}
	t=0;
	rep(i,1,w)
		if(lson[i]<=n)rson[lson[i]]=++t;
	rep(i,1,n-1)printf("%d ",rson[i]);
	printf("%d\n",rson[n]);
	return 0;
}
