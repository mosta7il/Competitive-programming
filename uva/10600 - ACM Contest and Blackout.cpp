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
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
vector< pair< int, pair<int, int > > > edge;
vector<int> MST, SMST;
vector<int> par;
vector<bool>vis;
ll fcost, scost , smn;

int find_root(int x){
	return x == par[x] ? x : par[x] = find_root(par[x]);
}
void unit(int a, int b){
	int u = find_root(a), v = find_root(b);

	par[u] = v;
}
int main(){

	fast();
	int t;
	cin >> t;

	while (t--){
		int n, m;
		cin >> n >> m;

		edge.clear();
		MST.clear(), SMST.clear();
		par.resize(n + 1, 0);
		edge.resize(m);
	

		lp(i, n+1)par[i] = i;

		lp(i, m){
			cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
		}

		sort(edge.begin(), edge.end());

		fcost = 0;
		lp(i, m){		//first Minimum Spanning Tree..
			int u = edge[i].second.first, v = edge[i].second.second, c = edge[i].first;
			if (find_root(u) != find_root(v)){
				fcost += c;
				MST.push_back(i);
				unit(u, v);
			}
		}
		
		smn = OO;
	lp(j , MST.size()){

			int node = 0;
			lp(i , n+1)par[i] = i;

			scost = 0;
			SMST.clear();

			lp(i , m){

				if (MST[j] == i)continue;

				int x = edge[i].second.first, y = edge[i].second.second, co = edge[i].first;
				
				if (find_root(x) != find_root(y)){
					node++;
					scost += co;
					unit(x, y);
				}
			}
			if (node == n-1){
				smn = min(smn, scost);
			}
		}
		cout << fcost << " " << smn << endl;
	}
	return 0;
}
//mosta7il_
