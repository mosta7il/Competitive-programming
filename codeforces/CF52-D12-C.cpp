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
#include<cstring>
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


const ll OO = 1e9+10;
const ll mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif

}
int n , q;
int a[15*200*1000+2];
ll tree[15*200*1000+2];
ll lazy[15*200*1000+2];
void build(int cur , int l , int r){
	if(l == r){
		tree[cur] = a[l];
		return ;
	}
	int md = (l+r)/2;
	int left = cur * 2 ;
	int right = left + 1;
	build(left , l , md);
	build(right , md+1 , r);
	tree[cur] = min(tree[left] , tree[right]);

}
void prop(int cur , int l , int r){

	if(lazy[cur]){
		tree[cur] +=  lazy[cur];
		if(l != r){
			lazy[cur *2] += lazy[cur];
			lazy[cur*2+1] +=lazy[cur];
		}
		lazy[cur] = 0;
	}

}
void update(int cur , int l , int r , int x , int y , ll v){
	prop(cur , l , r);
	if(x<= l &&y>= r){
		tree[cur] += v;
		lazy[cur*2]+=v;
		lazy[cur*2+1]+=v;
		return;
	}
	if(r < x || l> y){
		return;
	}
	int md = (l+r)/2;
	int left = cur * 2 ;
	int right = left + 1;
	update(left , l , md , x , y, v);
	update(right , md+1 , r , x , y , v);
	tree[cur] = min(tree[left] , tree[right]);
}

ll query(int cur , int l , int r , int x , int y){
	prop(cur , l , r);
	if(x<= l &&y>= r){
		return tree[cur];
	}
	if(r < x || l> y){
		return OO;
	}
	int md = (l+r)/2;
	int left = cur * 2 ;
	int right = left + 1;
	return min(query(left , l , md , x , y) , query(right , md+1 , r , x , y) );
}
int main(){
	fast();
	scanf("%d" , &n);
	fill(tree , tree + (15*200*1000+2) , OO);
	for(int i = 1 ; i <= n;i++){
		scanf("%d" , &a[i]);
	}
	build(1 , 1 , n);
	scanf("%d" , &q);
	getchar();
	string s;
	for(int i = 0 ; i < q;i++){
		
		getline(cin , s);
		stringstream ss;ss<<s;
		vector<int> v;
		int u;
		while(ss>>u){
			v.push_back(u);
		}

		if(v.size() == 2){
			ll rs = LLONG_MAX;
			if(v[0] > v[1]){
				rs = min(rs , query(1 , 1 , n , 1 , v[1]+1));
				rs = min(rs , query(1 , 1 , n , v[0]+1 , n));
			}else{
				rs = min(rs , query(1 , 1 , n , v[0]+1 , v[1]+1 ));
			}

			printf("%I64d\n",rs);
		}else{
			if(v[0] > v[1]){
				update(1 , 1 , n , 1 , v[1]+1 , v[2]);
				update(1 , 1 , n , v[0]+1 , n , v[2]);
			}else{
				update(1 , 1 , n , v[0]+1 , v[1]+1 , v[2] );
			}
		}
	}
	return 0;
}
