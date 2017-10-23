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
long long gcd(long long a, long long b)
{
	while (a&&b)a>b ? a %= b : b %= a;
	return a + b;
}
ll lcm(ll a, ll b){
	return  (a*b / gcd(a, b));
}
int n;

int main(){
	fast();
	cin >> n;
	if (n == 5){
		cout << "YES\n";
		cout << "5 - 1 = 4\n";
		cout << "4 - 2 = 2\n";
		cout << "4 * 3 = 12\n";
		cout << "12 * 2 = 24\n";
	}
	else if (n == 4){
		cout << "YES\n";
		cout << "4 * 2 = 8\n";
		cout << "8 * 3 = 24\n";
		cout << "24 * 1 = 24\n";
	}
	else if (n > 4){
		cout << "YES\n";
			cout << n << " - " << n - 1 << " = 1" << endl;
			cout << "1 - 1 = 0" << endl;
			n -= 2;
		while (n > 4){
			cout << n << " * 0 = 0" << endl;
			n--;
		}
		cout << "4 + 0 = 4\n" ;
		cout << "4 * 3 = 12\n";
		cout << "12 * 2 = 24\n";
	}
	else cout << "NO" << endl;
	return 0;
}
//mosta7il_
