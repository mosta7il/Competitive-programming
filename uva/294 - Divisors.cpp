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


const ll OO = 10e5;

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
int t , l ,r;

int divFromPrimeFactors(int x){
	if(x == 1)
		return 1;

	int rs = 1;
	for(int i = 2 ;i*i<=x;i++){
		int cnt = 0;
		while(x%i == 0){
			cnt++;
			x/=i;
		}
		rs*=(cnt+1);
	}
	if(x>1)
		rs*=2;
	return rs;
}

int main(){
	fast();

	cin>>t;
	while(t--){
		cin>>l>>r;
		int mxi = -1 , mx = -1;
		for(int i = l ;i<=r;i++){
			int rt = divFromPrimeFactors(i);
			if(mx < rt){
				mx = rt;
				mxi = i;
			}
		}
		cout<<"Between "<<l<<" and "<<r<<", "<<mxi<<" has a maximum of "<<mx<<" divisors.\n";
	}

	return 0;
}
