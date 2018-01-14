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


const ll OO = 10e5;

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
string ham;
int nb , ns , nc;
int b,s,c;
ll m , rs;
int hb , hs , hc;
bool fun(ll mid){

	ll neededPrice = max(0ll , hs * mid - ns) * s + max(0ll ,hb * mid - nb) * b + max(0ll ,hc * mid - nc)*c; 

	return (neededPrice <= m);
}
int main(){
	fast();

	cin>>ham>>nb>>ns>>nc;
	cin>>b>>s>>c;
	cin>>m;
	hb = count(all(ham),'B');
	hs = count(all(ham),'S');
	hc = count(all(ham),'C');


	ll lo = 0 , hi = 1e12+100;
	while(lo < hi){
		ll md = lo + (hi - lo + 1 )/2;
		if(fun(md))
			lo = md;
		else hi = md-1;
	}
	cout<<lo<<endl;
	return 0;
}
