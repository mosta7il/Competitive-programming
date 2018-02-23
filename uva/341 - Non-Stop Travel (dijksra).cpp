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


const ll OO = 1e6+1;
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

struct edge{
	int from , to ;ll cost;
	edge(int f , int t , ll w){
		from = f;to = t;cost = w;
	}
	bool operator < (const edge & e)const{
		return cost > e.cost;
	}
};
int n , u , v;
const int MAX = 11;
vector< edge >dp[MAX];
int path[MAX];
ll dist[MAX];
vector<int>ans;
void dij(int src){
	
	lp( i , n)
		dist[i] = OO , path[i] = -1;
	priority_queue< edge > p;
	p.push( edge(-1 , src , 0) );
	dist[src] = 0;
	while(!p.empty() ){
		edge cur = p.top();
		p.pop();

		if( cur.cost > dist[ cur.to ] )
			continue;
		path[ cur.to ] = cur.from;
		for(auto i : dp[cur.to] ){
			ll dis = dist[i.from] + i.cost;
			if(dis < dist[i.to]){
				i.cost = dist[i.to] = dis;
				p.push(i);
			}
		}
	}
}

int main(){
	fast();
	int ca = 0;
	while(cin>>n&& n){
		lp(i , n){
			dp[i].clear();
			int x;
			cin>>x;
			while(x--){
				cin>>u>>v;
				dp[i].push_back( edge( i ,u-1 , v) );
			}
		}
		int src , des;cin>>src>>des;
		src--, des--;
		int tmp = des;
		dij(src);
		ans.push_back(des+1);
		while(path[des]!=-1){
			ans.push_back(path[des]+1);
			des = path[des];
		}

		cout<<"Case "<<++ca<<": Path = ";
		for(int i = ans.size()-1;i>=0;i--){
			cout<<ans[i];
			if(i-1>= 0 )
				cout<<" ";
			else cout<<";";
		}
		ans.clear();
		cout<<" "<<dist[tmp]<<" second delay\n";
	}
	return 0;
}
//mosta7il_;
