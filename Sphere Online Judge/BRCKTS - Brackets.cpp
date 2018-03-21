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
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
}
int a[30*1000+2];
int n , m;
pair<int, int> tree[15 * 30 * 1000 + 2];
string inp;

void build(int cur , int l , int r){

	if(l == r){
		tree[cur].first = ((a[l] == 1)?1:0);
		tree[cur].second = ((a[l] == -1)?1:0);
		return ;
	}

	int mid = (l + r)/2;
	int left = cur * 2; 
	int right = left + 1;
	build(left , l , mid);
	build(right , mid+1 , r);
	
	tree[cur].first = tree[left].first + tree[right].first;
	tree[cur].second = tree[left].second+tree[right].second;

	int dif = min(tree[left].first , tree[right].second);
		tree[cur].first -= dif;

		tree[cur].second -= dif;
}
void update(int cur , int l , int r , int idx ){
	if( l == r){
		tree[cur].first = ((a[l] == 1)?0:1);
		tree[cur].second = ((a[l] == -1)?0:1);
		a[l] = -a[l];
		return ;
	}
	int mid = (l + r)/2;
	int left = cur * 2; 
	int right = left + 1;
	if(idx <= mid){
		update(left , l , mid , idx);
	}else{
		update(right , mid+1 , r , idx);
	}
	tree[cur].first = tree[left].first + tree[right].first;
	tree[cur].second = tree[left].second+tree[right].second;

	int dif = min(tree[left].first , tree[right].second);
		tree[cur].first -= dif;

		tree[cur].second -= dif;
}
int main(){
	fast();
	int T = 10 , id = 1;;
	while(T--){
		cout<<"Test "<<id++<<":\n";

		clr(a , 0);
		clr(tree , 0);
		cin>>n;
		cin>>inp;
		for(int i = 0 ;i<inp.size();i++){
			a[i+1] = (inp[i] == '(')?1:-1;
		}
		
		build( 1 , 1 , n);
		cin>>m;
		for(int i = 0 ; i <m;i++){
			int x;cin>>x;
			if(x == 0){
				cout<<(( tree[1] == MP(0 , 0) )?"YES":"NO")<<"\n";
			}else{
				update(1 , 1 , n , x);
			}

		}
	}
	return 0;
}
