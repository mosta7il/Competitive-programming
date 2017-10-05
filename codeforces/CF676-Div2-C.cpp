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


const ll OO = 1e18;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n , k;
int a[(int)1e5 + 2];
int b[(int)1e5 + 2];

string s;

int main(){
	fast();

	cin >> n >> k;
	cin >> s;
	lp(i, n){
		a[i + 1] = (s[i] == 'a');
		b[i + 1] = (s[i] == 'b');
		a[i + 1] += a[i];
		b[i + 1] += b[i];
	}
	ll mx = 0;
	lp(i, n){
		ll lo = i + 1, hi = n;
		while (lo < hi){
			ll md = lo + (hi - lo + 1) / 2;
			if (b[md] - b[i] <= k)lo = md;
			else hi = md - 1;
		}
		mx = max(mx, lo - i);
	}

	lp(i, n){
		ll lo = i + 1, hi = n;
		while (lo < hi){
			ll md = lo + (hi - lo + 1) / 2;
			if (a[md] - a[i] <= k)lo = md;
			else hi = md - 1;
		}
		mx = max(mx, lo - i);
	}

	cout << mx << endl;
	return 0;
}
//mosta7il_
