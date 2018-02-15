
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
int n;
pair<int ,int> a[100*1000+1];
ll pwr( ll a ,ll b ){
	if( b%2 == 0)return 1;
	if( b%2 == 1)return a;

	ll t = pwr(a , b/2);
	return t * t * pwr(a , b%2);
}

int rem;
int main(){
	fast();
	cin>>n;
	lp(i , n){
		cin>>a[i].first>>a[i].second;
	}
	sort(a ,a+n);
	for(int i = 1 ; i <n;i++){
		int x = a[i].first - a[i-1].first;
		while(x--&& a[i-1].second>1){
			 rem  = a[i-1].second %4;
			a[i-1].second/=4;
			if(rem)
				a[i-1].second++;
		}
		if(x==-1){
			a[i].second = max(a[i].second , a[i-1].second);
		}
	}
	while(a[n-1].second /4 + ((a[n-1].second%4)?1:0)> 1){
		rem = a[n-1].second%4;
		a[n-1].second/=4;
		if(rem)
			a[n-1].second++;
		a[n-1].first++;
	}
	cout<<a[n-1].first+1<<endl;
	return 0;
}
//mosta7il_
