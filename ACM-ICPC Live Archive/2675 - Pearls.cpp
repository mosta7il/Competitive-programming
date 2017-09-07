//regionals 2002 - Europe - Northwestern

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


const ll OO = 1e9;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;
pair<int, int> p[101];
map<pair<int, int> ,int > mem;
int rec(int idx, int sum){
	if (idx == n){
		return (sum + 10) * p[idx - 1].second;
	}
	if (mem.find({ idx, sum }) != mem.end())return mem[{idx, sum}];
	int ret = OO;
	ret = min(ret, rec(idx + 1, 0) + (sum+p[idx].first + 10)*p[idx].second);
	ret = min(ret, rec(idx + 1, sum + p[idx].first));

	return mem[{idx, sum}] = ret;
}

int main(){
	fast();
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> p[i].first >> p[i].second;
		}
		cout << rec(0, 0) << endl;
		mem.clear();
	}

	return 0;
}
//mosta7il_
