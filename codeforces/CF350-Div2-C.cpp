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


const ll OO = 1e18;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int n;
pair< ll, pair<ll, ll> > a[(int)1e5 + 2];
vector<pair<char , pair<ll , char> > >  v;

int main(){
	fast();
	scanf("%d", &n);

	lp(i, n){

		scanf("%lld", &a[i].second.first);
		scanf("%lld", &a[i].second.second);
		a[i].first = (a[i].second.first * a[i].second.first) + (a[i].second.second * a[i].second.second);
	}

	sort(a, a + n);

	lp(i, n){
		if (a[i].second.first){
			char s = ((a[i].second.first > 0) ? 'R' :'L');
			v.push_back({ '1', { abs(a[i].second.first), s } });
		}
		if (a[i].second.second){
			char s = ((a[i].second.second > 0) ? 'U' : 'D');
			v.push_back({ '1', { abs(a[i].second.second), s } });
		}
		v.push_back({ '2', { 0, 'N' } });
		if (a[i].second.first){
			char s = ((a[i].second.first > 0) ? 'L' : 'R');
			v.push_back({ '1', { abs(a[i].second.first), s } });
		}
		if (a[i].second.second){
			char s = ((a[i].second.second > 0) ? 'D' : 'U');
			v.push_back({ '1', { abs(a[i].second.second), s } });
		}
		v.push_back({ '3', { 0, 'N' } });
	}

	cout << v.size() << endl;
	lp(i, v.size()){
		
		printf("%c ", v[i].first);
		if (v[i].second.first == 0)printf("\n");
		else{
			printf("%d ", v[i].second.first);
			printf("%c\n", v[i].second.second);
		}
	}

	return 0;
}
//mosta7il_
