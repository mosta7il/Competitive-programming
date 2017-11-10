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
int t, n, m;
vector<int>par;
vector< pair< ll, pair<int, int> > > ed;
vector< pair<int, int> >v;
vector< pair <int, int > >MST;
int find_root(int a){
	if (a == par[a])
		return a;
	return par[a] = find_root(par[a]);
}
void unit(int a, int b){
	int roota = find_root(a), rootb = find_root(b);
	if (roota != rootb)
		par[roota] = rootb;
}
int main(){
	fast();
	
	cin >> t;
	while (t--){
		cin >> n;
		par.resize(n + 1, 0);
		lp(i, n + 1)par[i] = i;

		MST.clear();
		ed.clear();
		v.clear();
		v.resize(n);

		lp(i, n){
			cin >> v[i].first >> v[i].second;
		}
		lp(i, n){
			for (int j = i + 1; j < n; j++){
				ll co = (v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second);
				ed.push_back({ co, { i + 1, j + 1 } });
			}
		}
		sort(ed.begin(), ed.end());
		cin >> m;
		lp(i, m){
			int u, v;
			cin >> u >> v;
			unit(u, v);
		}
		lp(i, ed.size()){
			int u = ed[i].second.first, v = ed[i].second.second;
			if (find_root(u) != find_root(v)){
				MST.push_back({ u, v });
				unit(u, v);
			}
		}
		if (MST.size() == 0){
			cout << "No new highways need\n";
		}
		else{
			lp(i, MST.size()){
				cout << MST[i].first << " " << MST[i].second << endl;
			}
		}
		if (t)cout << endl;
	}
	return 0;
}
//mosta7il_
