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


const ll OO = 1e16;
const ll mod = 1e9+7;

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

int n;
ll x1, x2,ff,ff2;
vector< ll > d1 , d2;
vector< pair<ll , ll > > v;
bool fun(int idx , int md){
	
	lp(i , n){
		ll r = (v[i].first  - x1) * (v[i].first  - x1) + (v[i].second - ff) *(v[i].second - ff);
		ll rr = (v[i].first  - x2) * (v[i].first  - x2) + (v[i].second - ff2) *(v[i].second - ff2);
		if( r > d1[idx] && rr > d2[md] ){
			return 0;
		}
	}
	return 1;
}
int main(){
	fast();

	cin>>n;
	cin>>x1>>ff>>x2>>ff2;
	v.resize(n);
	d1.push_back(0);d2.push_back(0);
	lp( i ,n){
		cin>>v[i].first>>v[i].second;
		ll r = (v[i].first  - x1) * (v[i].first  - x1) + (v[i].second - ff) *(v[i].second - ff);
		ll rr = (v[i].first  - x2) * (v[i].first  - x2) + (v[i].second - ff2) *(v[i].second - ff2);
		d1.push_back(r);d2.push_back(rr);
	}
	sort(all(d1));sort(all(d2));
	ll mn = LLONG_MAX;
	for(int i = 0 ; i < d1.size() ;i++){
		
		int lo = 0 , hi = d2.size() ;ll ans  = -1;;
		while(lo<hi){
			int md = lo + ( hi - lo )/2;
			if( fun(i ,md) ){
				hi = md;
				ans = d1[i] + d2[md];
			}else{
				lo = md+1;
			}
		}
		mn = min(mn , ans);
	}
	cout<<mn<<endl;
	return 0;
}
//mosta7il_;
