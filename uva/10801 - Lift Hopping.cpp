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
struct edge {
	int from , to  ,  num;
	ll we;
	edge (int f , int t, int nn ,ll w){
		from = f , to = t , we = w,num=nn;
	}

	bool operator < (const edge & e) const {
        return we > e.we;
    }
};
int n , k ;
vector<edge> g[101];
vector< ll > dist;

int el[1001];
int a[101];

void dij(int src){

	priority_queue< edge > p ;
	p.push( edge(-1 , src,-1 , 0) );
	dist[src] = 0;
	while(!p.empty()){
		edge cur = p.top();
		p.pop();


		if(cur.we > dist[cur.to])
			continue;

		for(int i = 0 ; i<g[cur.to].size();i++){
			
			edge ne = g[cur.to][i];
			ll ad =0;
			if(cur.num !=-1 && ne.num != cur.num)
				ad+=60;
			if( dist[ne.to] > dist[ne.from] + ne.we+ad ){
				dist[ne.to] = ne.we = dist[ne.from] + ne.we+ad;
				p.push(ne);
			}
		}

	}
	
}
int main(){
	fast();

	while(cin>>n>>k){
		dist.clear();
		dist.resize(101 , OO);
		lp(i , 101)
			g[i].clear();
		int cnt = 0;
		string s;
		lp(i , n)
			cin>>a[i];
		cin.ignore();
		lp(i , n){
			cnt = 0;
			stringstream ss;
			
			getline( cin , s);
			ss<<s;
			while(ss>>el[cnt]){
				cnt++;
			}
			sort(el , el+cnt);
			for(int j = 0 ; j<cnt;j++){
				for(int w = j +1;w<cnt;w++){
					g[ el[j] ] .push_back( edge ( el[j] , el[w] , i , (el[w] - el[j]) * a[i] ) );
					g[ el[w] ] .push_back( edge ( el[w] , el[j] , i , (el[w] - el[j]) * a[i] ) );
				}
			}
		}
		dij(0);
		if(dist[k]<OO)
			cout<<dist[k]<<endl;
		else cout<<"IMPOSSIBLE\n";
	}
	
	return 0;
}
