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
int k;
string s;
int a[26];
int main(){
	fast();
	cin >> k;
	cin >> s;
	lp(i,( s.size()+1) / 2){
		char x = s[i], y = s[s.size() - 1 - i];
		if (x != y && (x != '?' && y != '?')){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		if ((isalpha(x) && x - 'a' >= k) || (isalpha(y) && y - 'a' >= k)){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

	lp(i, (s.size()+1) / 2){
		if (s[i] == '?' && s[s.size() - i - 1] != '?')		s[i] = s[s.size() - i - 1];
		else if (s[i] != '?' && s[s.size() - i - 1] == '?') s[s.size() - i - 1] = s[i] ;
	}
	int q = 0, cnt = 0;
	lp(i, s.size()){
		if (s[i] != '?')a[s[i] - 'a']++;
		else q++;
	}
	q = (q+1) / 2;
	
	lp(i, k){ cnt += a[i] == 0; }

	if (q<cnt){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	lp(i, (s.size()+1) / 2){
		if (s[i] == '?' && s[s.size() - i - 1] == '?'){
			if (q > cnt){
				s[i] = s[s.size() - 1 - i] = 'a';
				q--;
			}
			else{
				lp(j, k){
					if (a[j] == 0){
						a[j]++;
						s[i] = s[s.size() - i - 1] = (j + 'a');
						break;
					}
				}
			}
		}
	}

	cout << s << endl;
	return 0;
}
//mosta7il_
