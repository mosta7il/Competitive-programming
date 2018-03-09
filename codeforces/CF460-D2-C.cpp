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


const ll OO = 1e9;
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
ll n , m ,w;
ll a[100001];
bool fun(int md){
	ll cnt = 0;
	ll tmp[100001]={0};

	for(int i = 0 ;i < n ;i++){
	        if(i > 0)tmp[i]+=tmp[i-1];
	        if(md <= (a[i] + tmp[i] ) )
	                continue;
	        ll rem = md - (a[i] + tmp[i]);
	        cnt+=rem;
	        tmp[i]+=rem;
	        if(i + w < n)tmp[i+w]-=rem;
	}
	return (cnt <= m);
}
int main(){
	fast();
	
	cin>>n>>m>>w;
	lp(i , n){
		cin>>a[i];
	}
	int lo = 1 , hi = 1e9+1e5 , ans =-1;
	while(lo<=hi){
		int md = lo + (hi - lo+1)/2;
		if (fun(md)){
			lo = md+1;
			ans = md;
		}else{
			hi = md -1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
