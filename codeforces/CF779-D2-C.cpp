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
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int n, k;
pair<int, int> b[int(2e5) + 2];
pair<int, int> a[int(2e5) + 2];
bool cmp(pair<int, int> i, pair<int, int> j){
	return  (i.first - i.second < j.first - j.second);
	
}
ll cnt, c;
int main(){
	fast();
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i].first; b[i].first = a[i].first;
	}
	for (int i = 0; i < n; i++){
		cin >> a[i].second; b[i].second = a[i].second;
	}

	sort(a, a + n, cmp);
	sort(b, b + n);

	for (int i = 0; i < n; i++){
		if (i < k){
			cnt += a[i].first;
			c += b[i].first;
		}
		else{
			cnt += min(a[i].first, a[i].second);
			c += min(b[i].first, b[i].second);
		}
	}
	cout << min(c,cnt) << endl;
	return 0;
}
//mosta7il_
