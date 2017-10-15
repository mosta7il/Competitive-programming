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
int a[5];

bool rec(int i, int tot){
	
	if (i == 5){
		return (tot == 23);
		
	}
	if (rec(i + 1, tot + a[i]))return 1;
	if (rec(i + 1, tot * a[i]))return 1;
	if( rec(i + 1, tot - a[i]))return 1;
	return 0;
}
int main(){
	fast();
	
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] && a[0] != 0){
		sort(a, a + 5);
		bool f = 1;
		do{
			if (rec(1, a[0])){
				f = 0;
				cout << "Possible" << endl;
			}
		} while (f&&next_permutation(a, a + 5));
		if (f){
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
//mosta7il_
