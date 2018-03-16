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
int n , k ;
int a[1000*100+2];
int tree[20* (1000*100+1)];

void build(int cur , int l ,  int r){
	if(l == r){
		tree[cur] = ((a[l] > 0)?1:(a[l] <0)?-1:0);
		return ;
	}

	int mid = (r + l)/2;
	int left  = cur *2;
	int right = cur *2 + 1;
	build(left , l , mid);
	build(right , mid+1 , r);
	tree[cur] = tree[left] * tree[right];
}

void update(int idx , int val , int cur= 1 , int l = 1 , int r = n){
	if(l == r){
		tree[cur] = ((val > 0)?1:(val <0)?-1:0);
		return;
	}

	int mid = (l + r)/2;
	int left = cur * 2;
	int right = cur *2 + 1;

	if(idx <= mid){
		update(idx , val , left , l , mid);
	}else{
		update(idx , val , right , mid +1 , r);
	}
	tree[cur] = tree[left] * tree[right];
}

int query(int lo , int hi , int cur = 1 , int l = 1 , int r = n){

	if(lo<=l&&hi >=r){
		return tree[cur];
	}
	if(hi < l || lo > r){
		return 1;
	}

	int mid = (l + r)/2;
	int left = cur * 2;
	int right = cur *2 + 1;

	return query(lo , hi , left , l , mid) * query(lo , hi , right , mid+1 , r);
}
int main(){
	fast();
	while(cin>>n>>k){
		fill(tree , tree + 20*(100*1000+1) , 1);
		for(int i = 1; i<=n;i++){
			cin>>a[i];
		}
		build(1 , 1 , n);
		for(int i = 1 ; i <= k ;i++){
			char ch;cin>>ch;
			if(ch =='C'){
				int idx , val;
				cin>>idx >> val;
				update(idx , val);
			}else{
				int lo , hi;
				cin>>lo>>hi;
				int res = query(lo , hi);
				if(res==0)cout<<0;
				else if(res > 0)cout<<'+';
				else cout<<'-';
			}
		}
		cout<<endl;
	}
	return 0;
}
