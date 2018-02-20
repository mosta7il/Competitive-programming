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
const ll mod = 1e9+9;

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

ll n , k;
int d[100005];
vector<int> g[100001];
int zero ;
int mxl;
int main(){
	fast();
	cin>>n>>k;
	lp(i , n){
		cin>>d[i];
		g[d[i]].push_back(i+1);
		mxl  = max(mxl , d[i] );
		zero+=(!d[i]);
	}
	if(zero!= 1){
		cout<<-1<<endl;
		return 0;
	}
	vector< pair<int,int> > ans;
	for(int i = 1;i<=mxl;i++){
		int idx = 0;
		if(i == 1){
			if((1ll) * g[i-1].size() * k < g[i].size() ){
				cout<<-1<<endl;
				return 0;
			}
			idx = k;
		}else{
			if((1ll)*g[i-1].size() * (k-1) < g[i].size() ){
				cout<<-1<<endl;
				return 0;
			}
			idx = k-1;
		}
		int w = 0, tmp=0;
		for(int j = 0;w < g[i].size() && j<g[i-1].size();j++){
			tmp =idx;
			while(w < g[i].size() && tmp){
				ans.push_back( MP(g[i-1][j] , g[i][w]) );
				w++;
				tmp--;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i = 0 ; i < ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;

	return 0;
}
//mosta7il_;
