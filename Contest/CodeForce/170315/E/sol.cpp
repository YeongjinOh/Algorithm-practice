#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define bel(i) ((i)>>11)
#define lbt(i) ((i)&-(i))
using namespace std;
typedef long long LL;
int n,q;
const int MX=200011,B=2048;
int cnt[MX/B+2][MX],a[MX];
inline void add(int *c,int x,int d){
    for(int i=x;i<=n;i+=lbt(i))c[i]+=d;
}
inline int que(int *c,int x){
    int ans=0;for(int i=x;i;i^=lbt(i))ans+=c[i];
    return ans;
}
LL ans=0LL;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1;i<=n;i++)add(cnt[bel(i)],a[i],1);
    for(int i=1;i<=q;i++){
        int l,r;scanf("%d%d",&l,&r);
        if(l==r)goto E;
        if(l>r)swap(l,r);
        if(a[l]<a[r]){
            ans++;
            if(bel(l+1)==bel(r-1))for(int j=l+1;j<r;j++)ans+=2*(a[j]>a[l]&&a[j]<a[r]);
            else {
                for(int j=l+1;bel(j)==bel(l+1);j++)ans+=2*(a[j]>a[l]&&a[j]<a[r]);
                for(int j=r-1;bel(j)==bel(r-1);j--)ans+=2*(a[j]>a[l]&&a[j]<a[r]);
                for(int j=bel(l+1)+1;j<bel(r-1);j++)ans+=2*(que(cnt[j],a[r])-que(cnt[j],a[l]));
            }
        }else{
            ans--;
            if(bel(l+1)==bel(r-1))for(int j=l+1;j<r;j++)ans-=2*(a[j]>a[r]&&a[j]<a[l]);
            else {
                for(int j=l+1;bel(j)==bel(l+1);j++)ans-=2*(a[j]>a[r]&&a[j]<a[l]);
                for(int j=r-1;bel(j)==bel(r-1);j--)ans-=2*(a[j]>a[r]&&a[j]<a[l]);
                for(int j=bel(l+1)+1;j<bel(r-1);j++)ans-=2*(que(cnt[j],a[l])-que(cnt[j],a[r]));
            }
        }
        add(cnt[bel(l)],a[l],-1);
        add(cnt[bel(r)],a[r],-1);
        swap(a[l],a[r]);
        add(cnt[bel(l)],a[l],1);
        add(cnt[bel(r)],a[r],1);
E:printf("%lld\n",ans);
    }
    return 0;
}
