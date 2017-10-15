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
int t, n;
char g[4][4];
bool vis[4][4];
int sx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int sy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
int cost[] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
string s;
map<string, bool>mp;
bool isv(int i, int j){
	return (i >= 0 && j >= 0 && i < 4 && j < 4);
}
bool dfs(int i, int j, int ind){

	if (ind == s.size())return 1;

	for (int d = 0; d < 8; d++){
		int ii = i + sx[d], jj = j + sy[d];
		if (isv(ii, jj) && !vis[ii][jj]&&s[ind] == g[ii][jj]){
			vis[ii][jj] = 1;
			if (dfs(ii, jj, ind + 1))
				return 1;
		}
	}
	vis[i][j] = 0;
	return 0;
}
int main(){
	fast();
	ofstream fo("px.txt");
	cin >> t;
	int c = 1;
	while (t--){
		mp.clear();
		lp(i, 4)lp(j, 4)cin >> g[i][j];
		cin >> n;
		ll cnt = 0;
		lp(i, n){
			cin >> s;
			lp(x, 4){
				lp(y, 4){
					memset(vis, 0, sizeof vis);
					if (dfs(x, y, 0)){
						cnt+=cost[min(8,(int )s.size())];
						mp[s] = 1; break;
					}
				}
				if (mp[s])break;
			}
		}
		cout <<"Score for Boggle game #"<<c++<<": "<< cnt << endl;
	}

	return 0;
}
//mosta7il_
