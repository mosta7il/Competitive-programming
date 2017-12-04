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

int fun(int n){
	int sum = 0;
	if (n == 1)
		return 0;
	for (int i = 1; i*i <= n; i++){
		if (n %i == 0){
			sum += i;
			if (i * i != n && i!=1)sum += n / i;
		}
	}
	return sum;
}
int main(){
	fast();
	cout << "PERFECTION OUTPUT\n";
	while (cin >> n && n){
		int ret = fun(n);
		if ( ret== n)
			cout << setw(5) << n << "  " << "PERFECT\n";
		else if (ret < n) 	cout << setw(5) << n << "  " << "DEFICIENT\n";
		else cout << setw(5) << n << "  " << "ABUNDANT\n";
	}
	cout << "END OF OUTPUT\n";
	return 0;
}
//mosta7il_
