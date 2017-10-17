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
vector<ll> v;
ll gcd(ll a, ll b) {
	while (b){ int r = a % b; a = b; b = r; }
	return a;
}
int n;
int main(){
	fast();
	cin >> a >> b;
	ll gc = gcd(a, b);
	for (int i = 1; i*i <= gc; i++){
		if (gc%i == 0){
			v.push_back(i);
			v.push_back(gc / i);
		}
	}
	sort(v.begin(), v.end());
	cin >> n;
	while (n--){
		int l, r;
		cin >> l >> r;
		if (gc >= l && gc <= r)cout << gc << endl;
		else if (gc < l)cout << -1 << endl;
		else{
			int lo = -1, hi = v.size() - 1;
			int ans = -1;
			while (lo < hi){
				int md = lo + (hi - lo + 1) / 2;
				if (v[md] > r)hi = md-1 ;
				else if (v[md] < l)lo = md;
				else {
					lo = md; 
					ans = v[md];
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
//mosta7il_
