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
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;
string s;
int dp[100 * 1000 + 1][3][4];
int fun(int i, int l, int state){
	if (i == s.size())
		return 0;

	if (dp[i][l][state] != -1)return dp[i][l][state];
	int ret = -100;
	if (state == 0){
		ret = max(ret, fun(i + 1, (s[i] - '0') , state) + (l != (s[i] - '0')) );
		ret = max(ret , fun(i + 1, (1-(s[i] - '0')) , 1) + (l !=  1 - (s[i] - '0')));
	}
	else if (state == 1){
		ret = max(ret , fun(i + 1, (1 - (s[i] - '0')), 1) + (l != 1-(s[i] - '0')));
		ret = max(ret , fun(i + 1, (s[i] - '0'), 2) + (l != (s[i] - '0')));
	}
	else{
		ret = max(ret , fun(i + 1, (s[i] -'0') , state) + (l != (s[i] - '0')) );
	}
	return dp[i][l][state] = ret;
}
int main(){
	fast();
	while (cin >>n>>s){
		clr(dp, -1);
		cout << max(fun(0 , 0 , 0) , fun(0 , 1 , 0) ) << endl;
	}
	return 0;
}
//mosta7il_
