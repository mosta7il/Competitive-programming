#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long long         ll;
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef vector<ll>		  vll;


const ll OO = 1e11;
const ll mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif
}
int n  ,q;
int a[100*100+1];
int tree[15 * 100 * 100 + 1];
int lazy[15 * 100 * 100 + 1];

bool isp(int x){
	if(x == 1)
		return 0;
	if(x == 2)return 1;
	if(x %2 == 0)
		return 0;
	for(int i = 2 ; i * i <= x;i++){
		if(x % i == 0){
			return 0;
		}
	}
	return 1;
}
void build(int cur  , int l , int r ){
	if(l == r){
		tree[cur] = a[l];
		return ;
	}
	int md = (l + r)/2;
	int left = cur * 2;
	int right = left +1;
	build(left , l ,md);
	build(right , md+1 , r);
	tree[cur] = tree[left] + tree[right];
}
void propgate(int cur , int l , int r){
	if(lazy[cur] != -1 ){
		tree[cur] = (r-l+1)*lazy[cur];
		if(l != r){
			lazy[cur *2] = lazy[cur];
			lazy[cur * 2 + 1] = lazy[cur];
		}
		lazy[cur] = -1;
	}

}
void updateRange(int cur , int l , int r , int x , int y , int val){
	propgate(cur , l , r);
	if(x <=l && y>= r){
		tree[cur] = (r-l+1) * val;
		lazy[cur*2] = val;
		lazy[cur*2+1] = val;
		return;
	}
	if(r < x || l > y){
		return ;
	}
	int md = (l + r)/2;
	int left = cur * 2;
	int right = left +1;
	updateRange(left , l , md , x , y , val);
	updateRange(right , md+1 , r , x , y , val);
	tree[cur] = tree[left] + tree[right]; 
}

int query(int cur , int l , int r , int  x , int y){
	propgate(cur , l , r);
	if(x <=l && y>= r){
		return tree[cur];
	}
	if(r < x || l > y){
		return 0;
	}
	int md = (l + r)/2;
	int left = cur * 2;
	int right = left +1;
	return query(left , l ,md , x ,y) + query(right , md+1 , r, x ,y);
}
int main(){
	fast();
	int t , idx = 1;
	scanf("%d" , &t);
	while(t--){
		printf("Case %d:\n" , idx);
		idx++;
		clr(lazy , -1);
		clr(tree , 0);

		scanf("%d %d" , &n,&q);
		for(int i = 1 ;i <= n ;i++){
			scanf("%d" , &a[i]);
			a[i] = isp(a[i]);
		}
		build(1 , 1 , n);
		for(int i = 1 ; i <= q;i++){
			int ty;scanf("%d" , &ty);
			if(ty == 0){
				int x , y , v;
				scanf("%d %d %d" , &x,&y , &v);
				updateRange(1 , 1 , n , x , y , isp(v) );
			}else{
				int x ,y;
				scanf("%d %d" , &x , &y);
				printf("%d\n" , query(1 , 1 , n , x , y) );
			}

		}

	}
	return 0;
}
