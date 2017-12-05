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

string s, w, ss;
vector<int> a[26];
bool fun(int k){
	
	 int idx = 0;
	 for (int i = 0; i < w.size(); i++){
		 int lo = 0, hi = a[w[i] - 'a'].size();
		 while (lo < hi){
			 int md = lo + (hi - lo) / 2;
			 if (a[w[i] - 'a'][md] >= idx)
				 hi = md;
			 else lo = md + 1;
		 }
		 if (hi == a[w[i]-'a'].size() && k > 1){
			 k--;
			 idx = 0;
			 i--;
		 }
		 else if (hi == a[w[i] - 'a'].size() && k == 1){
			 return 0;
		 }
		 else idx = a[w[i] - 'a'][hi]+1;
	 }
	 return 1;
}
int main(){
	fast();
	
	while (cin >> s >> w){
		int as[26] = { 0 };
		bool f = 1;
		for (int i = 0; i < s.size(); i++){
			as[s[i] - 'a']++;
			a[s[i] - 'a'].push_back(i);
		}
		for (int i = 0; i < w.size(); i++){
			if (as[w[i] - 'a'] == 0){
				f = 0;
				break;
			}
		}
		if (!f){
			cout << -1 << endl;
			continue;
		}

		int lo = 1, hi = 1e6 + 1;
		while (lo < hi){
			int md = lo + (hi - lo) / 2;
			if (fun(md)){
				hi = md;
			}
			else lo = md + 1;
		}

		cout << hi << endl;
	}
	
	return 0;
}
//mosta7il_
