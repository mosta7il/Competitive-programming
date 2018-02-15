
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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n , m;
set<int>alive;
int ans[(int)4*100000+1];
int main(){
	fast();
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		alive.insert(i);
	for(int i = 0 ; i <m;i++){
		int l , r ,x;
		cin>>l>>r>>x;
		set<int>::iterator it = alive.lower_bound(l);
		vector<int> er;
		while( it != alive.end() ){
			if(*it > r)
				break;
			if(*it != x){
				ans[*it] = x;
				er.push_back(*it);
			}
			it++;
		}
		for(int j = 0 ; j <er.size() ; j++)
			alive.erase(er[j]);
	}
	for(int i = 1;i<=n;i++)
		cout<<ans[i]<<" ";

	return 0;
}
//mosta7il_
