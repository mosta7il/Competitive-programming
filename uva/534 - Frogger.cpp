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

int n;
double adj[201][201];
pair<int , int>a[201];
double calc(int i , int j){
	return sqrt((1.0)*(a[i].first - a[j].first) *(a[i].first - a[j].first) + (a[i].second - a[j].second) *(a[i].second - a[j].second));

}
int main(){
	fast();
	int cas = 1;
	while(cin>>n && n){
		lp(i ,n)
			cin>>a[i].first>>a[i].second;

		lp(i , n)lp(j,n){
			if(i == j)continue;
			double dis = calc(i , j);
			adj[i][j] = dis;
			adj[j][i] = dis;
		}

		lp(k , n)lp(i,n)lp(j,n){
			adj[i][j] = min(adj[i][j] , max(adj[i][k] ,adj[k][j]) );
		}
		cout<<"Scenario #"<<cas++<<endl;
		cout<<"Frog Distance = ";
		cout<<fixed<<setprecision(3)<<adj[0][1]<<endl<<endl;
	}
	return 0;
}
//mosta7il_;
