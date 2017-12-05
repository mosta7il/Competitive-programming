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

vector < pair<int, int> > p;
int main(){
	fast();
	int ca = 1;
	int t;
	cin >> t;
	while (cin >> n){
		cout << "Case #" << ca++ << ": " << n << " = ";
		p.clear();
		int cnt = 0;
		ll res = 1;
		for (ll i = 2; i*i <= n&&cnt<2; i++){
			while (n %i == 0 && cnt <2){
				p.push_back({ res * i, n / i });
				res *= i;
				n /= i;
				cnt++;
			}
		}
		for (int j = 0; j < p.size();j++){
			pair<int, int>i = p[j];
			cout << i.first << " * " << i.second;
			if (j + 1 < p.size()){
				cout << " = ";
			}
		}
		cout << endl;
		
	}
	
	return 0;
}
//mosta7il_
