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
ll a[5*1000*100+5];
int n;
ll k;
map< pair<int , pair<int , pair<ll ,bool> > > , ll>mem;
ll rec(int i , int cnt , ll sum, bool ok){
	if(cnt >2)
		return 0;
	
	if(mem.find(MP(i , MP(cnt , MP(sum ,ok) ) ) )!=mem.end())
		return mem[MP(i , MP(cnt , MP(sum ,ok) ) )];
	ll ret = 0;
	if(i == n)
		return (cnt == 2 && sum == k/3);
	if(sum == k/3&&ok)
		ret +=rec(i+1 , cnt+1 , a[i] , 1);
	ret += rec(i+1 , cnt ,sum+a[i] , 1);
	return mem[MP(i , MP(cnt , MP(sum ,ok) ) )] = ret;
}
int main(){
	fast();
	cin>>n;
	lp(i,n){
		cin>>a[i];
		k+=a[i];
	}
	if(k%3){
		cout<<0<<endl;
		return 0;
	}
	cout<<rec(0 , 0 ,0,0)<<endl;
	
	return 0;
}
