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


const ll OO = 1e9+1;
const ll mod = 1e9+9;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

void fast(){
	#ifndef ON+1LIN+1E_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
struct edge{
	int from , to , cost;
	edge(int f , int t , int c){
		from = f; to= t;cost = c;
	}
	bool operator < (const edge&e)const{
		return cost > e.cost;
	}
};
int t , m  ,n , src , des;
vector< edge > g[ 100*1000+2];
ll dist[1000*100 +2];
void dij(){
	for(int i = 1;i<=n;i++)
		dist[i]=OO;
	dist[src] = 0;
	priority_queue< edge > p;
	p.push( edge(-1 , src , 0) );
	while(!p.empty()){
		edge cur = p.top();
		p.pop();
		
		if( cur.cost > dist[ cur.to ] )continue;

		for(auto i : g[cur.to] ){
			int dis = cur.cost + i.cost;
			if( dist[ i.to ] > dis){
				i.cost = dist[i.to] = dis;
				p.push(i);
			}
		}
	}
}
int main(){
	fast();
	cin>>t;
	while(t--){
		
		cin>>n>>m;
		cin>>src>>des;
		for(int i = 1;i<=n;i++)
			g[i].clear();
		lp(i , m){
			int u , v,w;cin>>u>>v>>w;
			g[u].push_back( edge(u , v , w) );
			g[v].push_back( edge(v , u , w) );
		}

		dij();
		if(dist[des] == OO){
			cout<<"NONE\n";
		}else cout<<dist[des]<<endl;
	}
	return 0;
}
//mosta7il_;
