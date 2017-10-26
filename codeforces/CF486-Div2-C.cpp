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
string s;
int n, k;
int main(){
	fast();
	cin >> n >> k;
	cin >> s;
	ll cnt = 0;
	int t = 0;
	lp(i, s.size() / 2){
		if (s[i] != s[n - i -1])t++;
	}
	if (t == 0){
		cout << 0 << endl;
		return 0;
	}
	int lsofar = -1, rsofar = -1;
	if ((n + 1) / 2 < k){

		for (int i = k - 1; i < s.size(); i++){
			if (s[i] != s[n - i -1]){
				cnt += min(abs(s[i] - s[n - i -1]), abs(26 - abs(s[i] - s[n - i -1])));
				s[i] = s[n - i -1];
				lsofar = i - k + 1;
			}
		}

		for (int i = k - 1; i >= (n + 1) / 2; i--){
			if (s[i] != s[n - i -1]){
				cnt += min(abs(s[i] - s[n - i -1]), abs(26 - abs(s[i] - s[n - i -1])));
				s[i] = s[n - i -1];
				rsofar = k - 1 - i;
			}
		}
		if (rsofar == -1)cnt += lsofar;
		else if (lsofar == -1)cnt += rsofar;
		else cnt += (lsofar + rsofar + min(lsofar, rsofar));
	}
	else{
		
		for (int i = k - 1; i < (s.size() + 1) / 2; i++){
			if (s[i] != s[n - i -1]){
				cnt += min(abs(s[i] - s[n - i -1]), abs(26 - abs(s[i] - s[n - i -1])));
				s[i] = s[n - i -1];
				lsofar = i - k + 1;
			}
		}

		for (int i = k - 1; i >= 0; i--){
			if (s[i] != s[n - i -1]){
				cnt += min(abs(s[i] - s[n - i -1]), abs(26 - abs(s[i] - s[n - i -1])));
				s[i] = s[n - i -1];
				rsofar = k - 1 - i;
			}
		}
		if (rsofar == -1)cnt += lsofar;
		else if (lsofar == -1)cnt += rsofar;
		else cnt += (lsofar + rsofar + min(lsofar, rsofar));
	}

	cout << cnt << endl;

	return 0;
}
//mosta7il_
