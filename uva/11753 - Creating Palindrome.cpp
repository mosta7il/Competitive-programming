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


const ll OO = 9999999;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int n, k;
int s[100005];

int rec(int i, int j, int mv){

	if (mv > k)return OO;
	if (i >= j){
		return mv;
	}

	if (s[i] == s[j]){
		return rec(i + 1, j - 1, mv);
	}
	else{
		return  min(rec(i, j - 1, mv + 1), rec(i + 1, j, mv + 1));
	}

}

int main(){
	
	int t;
	cin >> t;
	int cs = 1;

	while (t--){

		scanf("%d", &n);
		scanf("%d", &k);

		for (int i = 0; i <n; i++)scanf("%d", &s[i]);

		int res = rec(0, n - 1, 0);

		cout << "Case " << cs++ << ": ";
		if (res == 0)cout <<"Too easy";
		else if (res <= k) cout << (res);
		else cout << ("Too difficult");
		cout << endl;

	}
	return 0;
}
//mosta7il_
