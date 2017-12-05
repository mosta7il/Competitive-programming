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

ll n;

map<int, int>p;
int main(){
	fast();

	while (cin >> n && n){
		p.clear();
		bool neg = (n < 0);
		(neg) ? n *= -1 : n;
		for (ll i = 2; i*i <= n; i++){
			while (n %i == 0){
				p[i]++;
				n /= i;
			}
		}
		if (n > 1)p[n]++;
		bool f = 1;
		for (ll i = 32; i >= 1; i--){
			for (auto it : p){
				 f = 1;
				if (it.second % i){
					f = 0;
					break;
				}
			}
			if (f && neg && i % 2 == 1){
				cout << i << endl;
				break;
			}
			else if (f && !neg){
				cout << i << endl;
				break;
			}
		}
		
	}
	
	return 0;
}
//mosta7il_
