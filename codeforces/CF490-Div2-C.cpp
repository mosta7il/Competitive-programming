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
ll a, b;
ll pw(ll x, ll y , ll md){
	if (y == 0)return 1;
	if (y == 1)return x;
	ll t = pw(x, y / 2 ,md);
	return ((t%md)*(t%md)*pw(x, y%2, md) % md)%md;
}
string s;
ll pre[1000 * 1000 + 1];
ll suf[1000 * 1000 + 1];

int main(){
	fast();
	cin >> s;
	cin >> a >> b;
	ll num = 0;
	for (int i = s.size() - 1 , p = 0; i >= 0; i--,p++ ){
		num += ((s[i] - '0') * pw(10, p, b) % b);
		num %= b;
		suf[i] = (s[i] =='0'|| i== 0)?-1:num;
	}
	num = 0;
	for (int i = 0; i < s.size(); i++){
		num *= 10;
		num += ((s[i] - '0') % a);
		num %= a;
		pre[i] = (i + 1 < s.size()) ? num : -1;
	}
	int ind = -1;
	for (int i = 0; i < s.size()-1; i++){
		if (pre[i] == 0 && suf[i + 1] == 0){
			ind = i; break;
		}
	}
	if (ind == -1){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i <= ind; i++)cout << s[i];
	cout << endl;
	for (int i = ind + 1; i < s.size(); i++)cout << s[i];
	cout << endl;
	return 0;
}
//mosta7il_
