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
int n , k , p;
vector<int>even , odd;
vector<int> g[100001];
int main(){
	fast();
	cin>>n>>k>>p;
	lp(i,n){
		int u;cin>>u;
		if(u%2)odd.push_back(u);
		else even.push_back(u);
	}
	for(int i = 0;i<k-p;i++){
		if(odd.size() == 0){
			cout<<"NO"<<endl;
			return 0;
		}
		g[i].push_back(odd[odd.size() -1]);
		odd.pop_back();
	}
	if(odd.size() % 2){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i = k-p;i<k;i++){
		if(odd.size() > 0 ){
			g[i].push_back(odd[odd.size()-1]);odd.pop_back();
			g[i].push_back(odd[odd.size()-1]);odd.pop_back();
		}else if( even.size() > 0 ){
			g[i].push_back( even[even.size()-1] );even.pop_back();
		}else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	while(even.size() > 0){
		g[0].push_back(even[even.size()-1]);
		even.pop_back();
	}
	while(odd.size() > 0){
		g[0].push_back(odd[odd.size()-1]);odd.pop_back();
		g[0].push_back(odd[odd.size()-1]);odd.pop_back();
	}
	cout<<"YES\n";
	lp(i , k){
		cout<<g[i].size()<<" ";
		lp(j , g[i].size() )
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
