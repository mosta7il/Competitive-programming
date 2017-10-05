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
int a, b, k;
int p[(int)1e6 + 2];
void sieve(){
	lp(i, (int)1e6 + 1)p[i] = 1;

	p[0] = p[1] = 0;

	for (int i = 2; i*i <= (int)1e6; i++){
		if (p[i]){
			for (int j = i * i; j <= (int)1e6; j += i)p[j] = 0;
		}
	}

}
bool fun(int m){

	for (int i = a; i <= b - m + 1; i++){
		if (p[i + m - 1] - p[i - 1] < k)return 0;
	}
	return 1;
}
int main(){
	fast();
	sieve();
	cin >> a >> b >> k;
	lp(i, (int)1e6) p[i + 1] += p[i];

	int lo = k, hi = b - a + 2;
	int ans = -1;
	while (lo < hi){
		int md = lo + (hi - lo) / 2;
		if (fun(md)){
			hi = md;
			ans = md;
		}
		else{
			lo = md +1;
		}
	}

	cout << ans << endl;
	return 0;
}
//mosta7il_
