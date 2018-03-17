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
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n , q;
ll tree[20*(2*1000*100 + 2)];
ll lazy[20*(2*1000*100 + 2)];


void propgate(int cur , int lo , int hi){
	if(lazy[cur] > 0){
		tree[cur] += (hi - lo +1 ) * lazy[cur];
		if(lo != hi){
			int left = cur * 2;
			int right = cur  *2 + 1;
			lazy[left]  += lazy[cur];
			lazy[right] +=lazy[cur];
		}
		lazy[cur] = 0;
	}

}

void updateRange(int x , int y ,int val, int cur , int lo , int hi){
	propgate(cur , lo , hi);
	if(x <= lo && y>= hi){
		tree[cur]+=(hi-lo+1);;
		if(lo != hi){
			lazy[cur*2]++;
			lazy[cur*2 + 1]++;
		}
		return ;
	}

	if(lo > hi||hi < x || lo > y){
		return ;
	}

	int md =(hi +lo) /2;
	int left = cur * 2;
	int right = cur  *2 + 1;
	propgate(cur , lo, hi);
	updateRange(x , y , val , left , lo , md);
	updateRange(x , y , val , right, md+1 , hi);
	tree[cur] = tree[left]+tree[right];
}
ll query(int x , int y , int cur , int lo , int hi){
	propgate(cur ,lo , hi);
	if(x <= lo && y >= hi){
		return tree[cur];
	}
	if(lo > hi||hi < x ||lo > y){
		return 0;
	}
	int md =(hi +lo) /2;
	int left = cur * 2;
	int right = cur  *2 + 1;
	return query(x , y , left , lo , md) + query(x , y , right , md+1 , hi);
}
int main(){
	//fast();
	int t;
	scanf("%d",&t);
	int idx = 1;
	while(t--){
		clr(lazy , 0);
		clr(tree , 0);
		printf("Scenario #%d:\n",idx);
		idx++;
		scanf("%d %d" , &n ,&q);
			
		for(int i = 1 ; i <=q;i++){

			 char s[20];int l , r;
			scanf("%s",&s);
			scanf("%d %d" , &l ,&r);
			
			if(strcmp( "answer" , s )==0){
				printf("%lld\n" , query(l , r , 1 , 1 , n));
			}else{
				printf("OK\n");
				updateRange(l , r , 1 , 1 , 1 , n);
			}
		}

	}
	return 0;
}
