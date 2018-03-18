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


const ll OO = 1e6;
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

int a[1000*100+1];
int tree[15 * 1000 * 100 + 1];

void build(int cur , int l , int r){
	if(l == r){
		tree[cur] = a[l];
		return;
	}
	int md = (l + r)/2;
	int left = cur * 2;
	int right = left +1;
	build(left , l , md);
	build(right ,md+1 , r);
	tree[cur] = min(tree[left] , tree[right]);

}
void update(int cur , int l , int r , int idx , int val ){
	
	if(l == r){
		tree[cur] = val;
		return;
	}
	
	int md = (l + r)/2;
	int left = cur * 2;
	int right = left +1;
	if(idx<= md){
		update(left,l,md,idx,val);
	}else{
		update(right,md+1,r,idx,val);
	}
	tree[cur] = min( tree[left] , tree[right] );
}

ll query(int cur , int l , int r , int  x , int y){
	
	if(x <=l && y>= r){
		return tree[cur];
	}
	if(r < x || l > y){
		return OO;
	}
	int md = (l + r)/2;
	int left = cur * 2;
	int right = left +1;
	return min(query(left , l ,md , x ,y) , query(right , md+1 , r, x ,y));
}
int main(){
	fast();
		fill(tree , tree + (15 * 1000 * 100 + 1) , OO);
		scanf("%d %d" , &n,&q);
		for(int i = 1 ; i <=n;i++)
			scanf("%d" , &a[i]);
		build(1 , 1 , n);
		for(int i = 1 ; i <= q;i++){
			char s[35];
			scanf("%s"  , &s);
			if(s[0] == 's'){
				vector<int> v;int num = 0;
				for(int j = 6;s[j];j++){
					if(!isdigit(s[j])){
						v.push_back(num);
						num = 0;
					}else{
						num*=10;
						num+= (s[j] - '0');
					}
				}
				 int t = a[v[0]];
				 for(int i=0;i<v.size();i++){
					int x = v[i] ;
					int y = v[(i+1)%(int)v.size()];
					a[x] = a[y] ;
				}
				 a[v[v.size()-1]] = t ;
				 for(int i=0;i<v.size();i++) 
					 update(1,1,n,v[i],a[v[i]]);
			}else{
				vector<int> v;int num = 0;
				for(int j = 6;s[j];j++){
					if(!isdigit(s[j])){
						v.push_back(num);
						num = 0;
					}else{
						num*=10;
						num+= (s[j] - '0');
					}
				}
				printf("%d\n" , query(1 , 1 , n , v[0] , v[1]) );
			}

		}

	return 0;
}
