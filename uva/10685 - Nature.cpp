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
int n , m , p;

void dfs(bool * vis ,vector<int>*g , int src){
	p++;
	vis[src] = 1;

	for(int i = 0 ; i <g[src].size();i++){
		int tt = g[src][i];
		if(!vis[tt]){
			dfs(vis , g ,tt);
		}
	}

}

int main(){
	fast();
	while(cin>>n>>m&&n){
		map<string ,int> ind;
		vector<int>g[5001];
		bool vis[5001] = {0};

		lp(i,n){
			string c;
			cin>>c;
			ind[c] = i;
		}
		lp(i , m){
			string  u , v; cin>>u>>v;
			g[ind[u]].push_back(ind[v]);
			g[ind[v]].push_back(ind[u]);
		}
		int rs = 0;
		for(int i = 0 ; i <n;i++){
			if(!vis[i]){
				p = 0;
				dfs(vis , g , i);
				rs = max(rs ,p);
			}
		}
		cout<<rs<<endl;
	}
	return 0;
}
