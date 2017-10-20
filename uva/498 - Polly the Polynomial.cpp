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
ll po(ll a, ll b){
	if (b == 0)return 1;
	if (b == 1)return a;

	ll t = po(a, b / 2);
	return t * t *po(a, b % 2);
}
vector<ll> c(10000000);
vector<ll>X(10000000);
int main(){
	fast();

	string cs;
	while (getline(cin, cs)){
		stringstream ss ,xx;
		ss << cs;
		int n = 0;
		while (ss >> c[n])n++;

		string xs;
		getline(cin, xs);
		xx << xs;
		int cnt = 0;
		int nn = 0;
		while (xx >>X[nn]){
			nn++;
		}
		for (int j = 0; j < nn; j++){
			ll res = 0;
			for (int i = 0; i < n; i++){
				res += c[i] * po(X[j], n - i - 1);
			}
			cout << res;
			if (j + 1 < nn)cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}
//mosta7il_
