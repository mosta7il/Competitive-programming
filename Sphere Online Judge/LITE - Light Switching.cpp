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

pair<int, int> tree[15 * 1000 * 100 + 1];
int lazy[15 * 1000 * 100 + 1];
void propgate(int cur , int l , int r){
	if(lazy[cur] != 0 ){
		swap(tree[cur].first , tree[cur].second);
		if(l != r){
			lazy[cur*2] =!lazy[cur*2];
			lazy[cur*2+1] = !lazy[cur*2+1];
		}
		lazy[cur] = 0;
	}

}
void build(int cur , int l , int r){
	if(l == r){
		tree[cur].first = 0;
		tree[cur].second = (r-l+1);
		return;
	}
	int md = (l + r)/2;
	int left = cur * 2;
	int right = left +1;
	build(left , l , md);
	build(right ,md+1 , r);
	tree[cur].first = tree[left].first + tree[right].first;
	tree[cur].second = tree[left].second + tree[right].second;

}
void updateRange(int cur , int l , int r , int x , int y ){
	propgate(cur , l , r);
	if(x <=l && y>= r){
		swap(tree[cur].first , tree[cur].second);
		lazy[cur*2] =!lazy[cur*2];
		lazy[cur*2+1] = !lazy[cur*2+1];
		return;
	}
	if(r < x || l > y){
		return ;
	}
	int md = (l + r)/2;
	int left = cur * 2;
	int right = left +1;
	updateRange(left , l , md , x , y );
	updateRange(right , md+1 , r , x , y );
	tree[cur].first = tree[left].first + tree[right].first; 
	tree[cur].second = tree[left].second + tree[right].second;
}

ll query(int cur , int l , int r , int  x , int y){
	propgate(cur , l , r);
	if(x <=l && y>= r){
		return tree[cur].first;
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

		scanf("%d %d" , &n,&q);
		build(1 , 1 , n);
		for(int i = 1 ; i <= q;i++){
			int ty;scanf("%d" , &ty);
			if(ty == 0){
				int x , y ;ll v;
				scanf("%d %d" , &x,&y );
				updateRange(1 , 1 , n , x , y  );
			}else{
				int x ,y;
				scanf("%d %d" , &x , &y);
				printf("%lld\n" , query(1 , 1 , n , x , y) );
			}

		}

	return 0;
}
