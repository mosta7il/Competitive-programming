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
int n , k;
string s;
ll dp[5 * 1000 * 100 + 5][30];
ll rec(int i , int last ){

	if(i == n){
		return 0;
	}
	ll &ret = dp[i][last];
	if (ret != -1)
		return ret;
	ret = OO;
	if (s[i] != char(last + 'A'))
		return ret = rec(i + 1, s[i] - 'A');

	for(int idx = 0 ; idx < k;idx++){
		if(idx!= last)
			ret =min(ret , rec(i+1 , idx)+(s[i]!= (idx+'A')));
	}
	return ret;
}
void build(int i , int last){

	if(i == n){
		return ;
	}
	ll ret = dp[i][last];
	if (s[i] != char(last + 'A')){
		cout<<s[i];
		return build(i+1,s[i]-'A');
	}
	for(int idx = 0 ; idx < k;idx++){
		if(idx!= last)
			if ( ret == rec(i+1 , idx)+(s[i]!= (idx+'A')) ){
				cout<<char(idx+'A');
				return build(i+1 , idx);
			}
	}
}
int main(){
	fast();
	while(cin>>n>>k){
		clr(dp,-1);
		cin>>s;
		ll ret = OO;
		int state = 0;
		lp(i,26){
			ll rs = rec(0 , i);
			if( rs < ret ){
				ret = rs;
				state = i;
			}

		}
		cout<<ret<<endl;
		build(0 , state);
	}
	return 0;
}
