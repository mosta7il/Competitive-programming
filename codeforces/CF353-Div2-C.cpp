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
char x[(int)1e5 + 5];
ll a[(int)1e5 + 5];

int main(){
	fast();
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cin >> x;
	int last = -1;
	ll sum = 0;
	for (int i =1; i <= n; i++){
		if (x[i-1] == '1'){
			sum += a[i];
		}
		
	}
	ll mx = sum;
	ll s = 0;
	bool f = 0;
	for (int i = 0; i < n; i++){
	 if (x[i] == '1' &&f){
		 mx = max(mx, sum - a[i + 1] + s);
	 }
	 else if (x[i] == '0'){
		 f = 1;
		 s += a[i + 1];
	 }
	}
	cout << mx << endl;
	return 0;
}
//mosta7il_
