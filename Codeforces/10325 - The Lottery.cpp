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
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

struct edge{
	int from, to, w;
	edge(int f, int t, int w) :from(f), to(t), w(w){}

	bool operator < (const edge &e)const{
		return w > e.w;
	}
};
ll cnt1, cnt2;
ll n, m;
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b){
	return a*b / gcd(a, b);
}
int main(){
	fast();

	while (cin >> n >> m){
		vll p(m);
		lpi(i, 0, m)cin >> p[i];

		cnt1 = cnt2 = 0;

		//ll opsize = pow(2.00, m);

		for (int i = 1; i < (1<<m); i++){
			int c = 0; ll w = 1;
			for (int j = 0; j < m; j++){
				if (i & (1 << j)){
					w = lcm(w, p[j]);
					c++;
				}
			}
			if (c % 2 == 0){ cnt2 += (n/w); }
			else { cnt1 += (n/w); }
		}
		cout <<( n - (cnt1 - cnt2)) << endl;
	}


	return 0;
}
//mosta7il_
