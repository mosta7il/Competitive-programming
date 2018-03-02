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


const ll OO = 1e9;
const ll mod = 1e9 + 7;
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
int n , cnt;
vector<ll> a;
ll sum;
int main(){
	fast();
	cin>>n;
	lp(i , n){
		int u;
		cin>>u;
		a.push_back(u);
	}
	if(n < 3){
		cout<<n<<endl;
		return 0;
	}
	sort(a.begin() , a.end() );
	sum+=a[0];
	a.erase(a.begin());
	sum+=a[0];
	a.erase(a.begin());
	cnt =2;
	bool f = 1;
	while(f){

		int lo = 0 , hi = a.size()-1 ,ans =-1;
		while(lo<=hi){
			int md = lo + (hi - lo);
			if( a[md] >= sum ){
				hi = md-1;
				ans = md;
			}else{
				lo = md + 1;
			}
		}
		if(ans!=-1){
			cnt++;
			sum+=a[ans];
			a.erase(a.begin() + ans);
		}else{
			f=0;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
