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
const int MAX = 11;
ll dp[MAX][MAX];
int path[MAX][MAX];
vector<int>pp;
int l , r;
void build(int i , int j){
	while(path[i][j] != l){
            pp.pb(path[i][j]);
            j = path[i][j];
      }
}
int main(){
	fast();
	int ca = 0;
	while(cin>>n&& n){
		
		lp(i , n)
			lp(j , n){
				dp[i][j]=OO; 
				path[i][j]=-1;;
		}

		lp(i , n)lp(j , n){
			if(i == j){
				dp[i][i] = 0;
				path[i][i] = i;
			}
		}

		lp(i , n){
			int u;cin>>u;
			lp( j , u ){
				int x,y;
				cin>>x>>y;
				x--;
				dp[i][x]=y;
				path[i][x] = i;
			}
		}
		lp(k , n)lp(i , n) lp(j ,n)
			if(dp[i][k] < OO && dp[k][j] < OO){
				if( (dp[i][k] + dp[k][j]) <dp[i][j] ){
					path[i][j]= path[k][j];
					dp[i][j] = (dp[i][k] + dp[k][j]);
				}
			}
		
		cin>>l>>r;
		l--;r--;
		
		cout<<"Case "<<++ca<<": Path = ";
		pp.push_back(r);
		build(l , r);
		pp.push_back(l);
		for(int i = pp.size()-1;i>=0;i--){
			cout<<pp[i]+1;
			if(i-1>= 0 )
				cout<<" ";
			else cout<<";";
		}
		pp.clear();
		cout<<" "<<dp[l][r]<<" second delay\n";
	}
	return 0;
}
//mosta7il_;
