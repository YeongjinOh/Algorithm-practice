#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    node *ch[2];
    int val,pri,sz;
    node(int x){
        ch[0]=ch[1]=NULL;
        val=x,pri=rand(),sz=1;
    }
    int cmp(int x){
        if(x==val) return -1;
        return x<val?0:1;
    }
    void pull(){
        sz=1;
        if(ch[0]!=NULL) sz+=ch[0]->sz;
        if(ch[1]!=NULL) sz+=ch[1]->sz;
    }
}*root[200005];
void rotate(node* &o,int d){
    node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->pull(),k->pull();
    o=k;
}
void insert(node* &o,int x){
    if(o==NULL) o=new node(x);
    else{
        int d=o->cmp(x);
        insert(o->ch[d],x);
        if(o->ch[d]->pri>o->pri) rotate(o,d^1);
        o->pull();
    }
}
void remove(node* &o,int x){
    int d=o->cmp(x);
    if(d==-1){
        if(o->ch[0]==NULL) o=o->ch[1];
        else if(o->ch[1]==NULL) o=o->ch[0];
        else{
            int d2=o->ch[0]->pri>o->ch[1]->pri?1:0;
            rotate(o,d2);
            remove(o->ch[d2],x);
        }
    }
    else remove(o->ch[d],x);
    if(o!=NULL) o->pull();
}
long long ra(node* &o,int x){
    node* k=o;
    long long ret=0;
    while(k!=NULL){
        int d=k->cmp(x);
        if(d){
            ret++;
            if(k->ch[0]!=NULL) ret+=k->ch[0]->sz;
            k=k->ch[1];
        }
        else k=k->ch[0];
    }
    return ret;
}
int n,q,a[200005];
void add(int x,int v){
    while(x<=n) insert(root[x],v),x+=(x&(-x));
}
void sub(int x,int v){
    while(x<=n) remove(root[x],v),x+=(x&(-x));
}
long long query(int x,int v){
    if(!x) return 0;
    long long ret=0;
    while(x) ret+=ra(root[x],v),x-=(x&(-x));
    return ret;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        a[i]=i;
        add(i,i);
    }
    long long now=0;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y) {printf("%lld\n",now);continue;}
        if(x>y) swap(x,y);
        now+=2*((query(y-1,a[y])-query(x,a[y]))-(query(y-1,a[x])-query(x,a[x])));
        if(a[x]<a[y]) now++;
        else now--;
        printf("%lld\n",now);
        sub(y,a[y]),sub(x,a[x]),add(x,a[y]),add(y,a[x]);
        swap(a[x],a[y]);
    }
    return 0;
}
