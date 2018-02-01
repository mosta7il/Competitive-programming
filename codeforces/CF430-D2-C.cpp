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
const ll mod = 1e9+7;
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
vector<int> g[100005];
bool vis[ 100005 ];
int init[ 100005 ] ;
int goal[ 100005 ] ;
vector<int> ans;
void dfs(int src ,int dep , int even , int odd){
	vis[src] =1;
	if( (even % 2 && dep % 2 == 0) || (dep % 2 && odd % 2)){
		init[src] = !init[src];
	}
	if(init[src] != goal[src]){
		ans.push_back(src);
		init[src] = goal[src];
		if(dep%2)
			odd += 1;
		else even += 1;
	}
	for(int i = 0 ;i <g[src].size();i++){
		int tt = g[src][i];
		if(!vis[tt]){
			dfs(tt , dep+1 , even , odd);
		}
	}

}
int main(){
	fast();
	
		int u , v;
		cin>>n;
		lp(i , n-1 ){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		lp(i , n)
			cin>>init[i+1];
		lp( i , n )
			cin>>goal[i+1];
		dfs(1 ,0, 0 , 0);
		
		cout<<ans.size()<<endl;
		lp(i , ans.size() )
			cout<<ans[i]<<endl;

	return 0;
}
