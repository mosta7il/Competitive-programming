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
int n;
vector<int>prime;
bool a[1000005];
void sieve(){

	a[0]=a[1]= 1;
	for(int i = 2;i*i<1000005;i++){
		if(!a[i]){
			for(int j = i * i ; j<1000005;j+=i)
				a[j] = 1;
		}
	}

}
int b[100005];
int ind[100005];;
vector< pair<int ,int> > ans;
int main(){
	fast();
	cin>>n;
	sieve();
	lp(i , n+1){
		if(!a[i])
			prime.pb(i-1);
	}
	lp(i , n){
		cin>>b[i];
		ind[ b[i] ] = i;
	}
	for(int i = 1;i<=n;i++){
		int idx = ind[ i ] - (i-1);
		if(idx<0)
			idx*=-1;
		while(ind[i] != (i-1)){
			int lo = -1 , hi = prime.size()-1 , w = 0;
			while(lo<hi){
				int md = lo + (hi - lo +1)/2;
				if(prime[md] <= idx){
					lo = md;
					w = prime[md];
				}else{
					hi = md -1;
				}
			}
			int curs = ind[i] - w;
			ans.push_back(MP(ind[i]+1 , curs+1));
			swap( ind[i] , ind [ b[curs] ]);
			swap( b[ ind[i] ] , b[ ind [ b[curs] ]]);
			idx -= w;
			
		}
	}
	cout<<ans.size()<<endl;
	for(int i = 0 ; i < ans.size() ; i++){
		cout<<min(ans[i].first , ans[i].second)<<" "<<max(ans[i].first , ans[i].second)<<endl;
	}
	return 0;
}
//mosta7il_;
