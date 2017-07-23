#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 200005
#define MAXS 600005
#define MAXT 8000005
#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)|1)

struct SBTnode{
	int lc,rc,sz,key;
}T[MAXT];
int root[MAXS],rpos[MAXN];
int N,Q,SBTtot;
long long ans=0;

void _read(int &x)
{
	char tt=getchar();
	while(tt<'0'||'9'<tt) tt=getchar();
	for(x=0;'0'<=tt&&tt<='9';x=x*10+tt-'0',tt=getchar());
}

void _Left_Rotate(int &x)
{
	int k=T[x].rc;
	T[x].rc=T[k].lc;
	T[k].lc=x;
	T[k].sz=T[x].sz;
	T[x].sz=T[T[x].lc].sz+T[T[x].rc].sz+1;
	x=k;
}

void _Right_Rotate(int &x)
{
	int k=T[x].lc;
	T[x].lc=T[k].rc;
	T[k].rc=x;
	T[k].sz=T[x].sz;
	T[x].sz=T[T[x].lc].sz+T[T[x].rc].sz+1;
	x=k;
}

void _Maintain(int &x,bool flag)
{
	if(flag)
	{
		if(T[T[T[x].rc].rc].sz>T[T[x].lc].sz)
			_Left_Rotate(x);
		else if(T[T[T[x].rc].lc].sz>T[T[x].lc].sz)
			_Right_Rotate(T[x].rc),_Left_Rotate(x);
		else return;
	}
	else
	{
		if(T[T[T[x].lc].lc].sz>T[T[x].rc].sz)
			_Right_Rotate(x);
		else if(T[T[T[x].lc].rc].sz>T[T[x].rc].sz)
			_Left_Rotate(T[x].lc),_Right_Rotate(x);
		else return;
	}
	_Maintain(T[x].lc,0);
	_Maintain(T[x].rc,1);
	_Maintain(x,0);
	_Maintain(x,1);
}

void _Insert(int &x,int key)
{
	if(!x)
	{
		x=++SBTtot;
		T[x].key=key;
		T[x].sz=1;
		T[x].lc=T[x].rc=0;
		return;
	}
	T[x].sz++;
	if(key<T[x].key)
		_Insert(T[x].lc,key);
	else
		_Insert(T[x].rc,key);
	_Maintain(x,key>=T[x].key);
}

void _Add(int id,int Left,int Right,int key,int loc)
{
	_Insert(root[id],key);
	if(Left==Right) return;
	int Mid=(Left+Right)>>1;
	if(loc<=Mid)
		_Add(lson(id),Left,Mid,key,loc);
	else
		_Add(rson(id),Mid+1,Right,key,loc);
}

int _Delete(int &x,int key)
{
	T[x].sz--;
	int rt;
	if(key==T[x].key||(key>T[x].key&&(!T[x].rc)))
	{
		rt=T[x].key;
		if((!T[x].lc)||(!T[x].rc))
			x=T[x].lc+T[x].rc;
		else
			T[x].key=_Delete(T[x].lc,key+1);
		return rt;
	}
	if(key<T[x].key)
		return _Delete(T[x].lc,key);
	else
		return _Delete(T[x].rc,key);
}

void _Del(int id,int Left,int Right,int key,int loc)
{
	_Delete(root[id],key);
	if(Left==Right) return;
	int Mid=(Left+Right)>>1;
	if(loc<=Mid)
		_Del(lson(id),Left,Mid,key,loc);
	else
		_Del(rson(id),Mid+1,Right,key,loc);
}

int _Find(int &x,int key)
{
	if(!x) return 1;
	if(key<T[x].key)
		return _Find(T[x].lc,key);
	else
		return T[T[x].lc].sz+1+_Find(T[x].rc,key);
}

int _More(int id,int Left,int Right,int key,int loc)
{
	int rt=0;
	if(Right<loc)
		return T[root[id]].sz+1-_Find(root[id],key);
	if(Left<Right)
	{
		int Mid=(Left+Right)>>1;
		if(Left<loc)
			rt+=_More(lson(id),Left,Mid,key,loc);
		if((Mid+1)<loc)
			rt+=_More(rson(id),Mid+1,Right,key,loc);
		return rt;
	}
	return 0;
}

int _Less(int id,int Left,int Right,int key,int loc)
{
	int rt=0;
	if(loc<Left)
		return _Find(root[id],key)-1;
	if(Left<Right)
	{
		int Mid=(Left+Right)>>1;
		if(loc<Mid)
			rt+=_Less(lson(id),Left,Mid,key,loc);
		if(loc<Right)
			rt+=_Less(rson(id),Mid+1,Right,key,loc);
		return rt;
	}
	return 0;
}

void _init()
{
	_read(N);_read(Q);
	for(int i=1;i<=N;i++)
	{
		rpos[i] = i;
		//_read(k);
		//pos[k]=i;
		_Add(1,1,N,i,i);
	}
	ans = 0;
}

char t[100];
void _write(long long x,int j=1)
{
    if(x==0)printf("0");
    for(;x;x/=10,j++) t[j]=x%10+'0';
    for(j--;j;j--)putchar(t[j]);
    putchar('\n');
}

void _solve()
{
	for(int i = 1; i <= Q; ++ i){
		int l, r;
		_read(l); _read(r);
		if(l == r){
			_write(ans);
			continue;
		}
		if(l > r) std::swap(l, r);
		if(rpos[l] < rpos[r]){
			ans ++;
		}
		else{
			ans --;
		}
		if(l < r - 1){
			ans += _More(1, 1, N, rpos[l], r) - _More(1, 1, N, rpos[l], l + 1);
			ans -= _Less(1, 1, N, rpos[l], l) - _Less(1, 1, N, rpos[l], r - 1);
			ans -= _More(1, 1, N, rpos[r], r) - _More(1, 1, N, rpos[r], l + 1);
			ans += _Less(1, 1, N, rpos[r], l) - _Less(1, 1, N, rpos[r], r - 1);
		}
		_Del(1, 1, N, rpos[l], l);
		_Del(1, 1, N, rpos[r], r);
		_Add(1, 1, N, rpos[l], r);
		_Add(1, 1, N, rpos[r], l);
		std::swap(rpos[l], rpos[r]);
		_write(ans);
	}

	/*
	int k;
	for(int i=1;i<=M;i++)
	{
		_write(ans);
		_read(k);
		_Del(1,1,N,k,pos[k]);
		ans-=_More(1,1,N,k,pos[k])+_Less(1,1,N,k,pos[k]);
	}
	*/
}

int main()
{
	_init();
	_solve();
	return 0;
}
