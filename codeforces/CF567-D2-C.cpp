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
int n , k;
int a[2*1000*100+2];
map<ll , vector<int> > mp;

int main(){
	fast();
	cin>>n >> k;
	lp(i , n){
		cin>>a[i];
		mp[a[i]].push_back(i);
	}
	ll cnt = 0;
	lp(i , n){
		if(a[i] % k )
			continue;

		ll md = a[i];
		ll frst = a[i] / k;
		ll lst = (1ll) * a[i] * k ;
		int lo = 0 , hi = mp[frst].size()-1, ans =-1;
		while(lo <= hi){
			int md = lo + (hi -lo+1)/2;
			if(mp[frst][md] < i ){
				lo = md+1;
				ans = md;
			}else hi = md -1;
		}
		ll rs = ans+1;
		 lo = 0 , hi = mp[lst].size()-1;
		ans= -1;
		while(lo<=hi){
			int mid = lo + ( hi - lo ) /2;
			if(mp[lst][mid] > i){
				hi = mid-1;
				ans = mid;
			}else lo = mid + 1;
		}
		if(ans !=-1)
			rs = rs * (mp[lst].size() - ans);
		else rs = 0;
		cnt+= rs;
	}
	cout<<cnt<<endl;
	return 0;
}
//mosta7il_;
