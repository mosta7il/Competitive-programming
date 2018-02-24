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


const ll OO = 1e9+1;
const ll mod = 1e9+9;

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
ll a ,b;
string s;
int c[101];
int g[101];
int main(){
	fast();
	cin>>a>>b;
	cin>>s;
	if(a == 0 && b == 0){
			cout<<"Yes\n";
			return 0;
	}
	int totx = 0 , toty = 0;
	lp( i , s.size() ){
		if(s[i] == 'U' )toty++;
		if(s[i] == 'D' )toty--;
		if(s[i] == 'R' )totx++;
		if(s[i] == 'L' )totx--;
		c[i] = totx;
		g[i] = toty;
	}
	bool f=0 , ff = 0;
	lp(i , s.size() ){

		ll z = -1 , zz =-1;
		ll des = a - c[i];
		ll des1 = b - g[i];
		if( totx == 0){
			if(c[i] == a)
				z = -100;
		}else{
			if(((des % totx)+totx)%totx== 0 &&des/totx>=0){
				z = des/totx;
			}
		}
		if(toty == 0){
			if(g[i] == b)
				zz = -100;
		}else{
			if(((des1 % toty)+toty)%toty == 0&& des1/toty >= 0)
				zz = des1/toty;
		}
		if( z == zz && z !=-1 ){
			cout<<"Yes\n";
			return 0;
		}
		if(min(z,zz) == -100 && max(z,zz) !=-1){
			cout<<"Yes\n";
			return 0;
		}

	}
	cout<<"No\n";
	return 0;
}
//mosta7il_
