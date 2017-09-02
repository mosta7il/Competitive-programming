// C. Hard problem


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

int n;
string s[100002];
ll c    [100002];
map< pair<int, string >, ll> mem;
ll rec(int i, string prev){
	if (i == n)return 0;


	string w = s[i];
	reverse(w.begin(), w.end());
	if (s[i].compare(prev) < 0 && w.compare(prev) < 0)return OO;

	if (mem.find({ i, prev }) != mem.end())return mem[{i, prev}];

	ll ret = OO;
	if (i == 0){
		ret = min(ret, rec(i + 1 , s[i]));
		ret = min(ret, rec(i + 1 , w) + c[i]);
	}

	
	if (i!=0&&s[i].compare(prev) >= 0)
		ret = min(ret, rec(i + 1, s[i]));

	
	if (i!=0&&w.compare(prev)>=0 )
		ret = min(ret, rec(i + 1, w) + c[i]);

	return mem[{i, prev}] = ret;
}

int main(){
	fast();
	cin >> n;
	for (int i = 0; i < n; i++)cin >> c[i];
	for (int i = 0; i < n; i++)cin >> s[i];
	ll res = rec(0, "");

	if (res >= OO){
		cout << -1 << endl;
	}
	else{
		cout << res << endl;
	}

	return 0;
}
//mosta7il_
