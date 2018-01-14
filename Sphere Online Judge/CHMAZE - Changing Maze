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
char g[21][21][11];
bool vis[21][21][11];
int level[21][21][11];

int dx[]={0 , 0, 0 , 1 , -1};
int dy[]={0 , 1 , -1 ,0 , 0};
bool isv(int i , int j){
	return (i>=0&&j>=0&&j<m&&i<n);
}
int main(){
	fast();
	int c = 0;
	while(cin>>n>>m>>p&&n){
		clr(vis , 0);
		clr(level , 21*21*11);

		lp(i,p)
			lp(j,n)
				lp(k , m) cin>>g[j][k][i];

		queue< pair<int , pair<int , int> > > q;
		q.push(make_pair(0 , make_pair(0 , 0 ) ));
		level[0][0][0] = 0;
		bool f = 0;
		while(!q.empty()){
			int x = q.front().second.first , y = q.front().second.second;
			int pi = q.front().first;
			q.pop();
			vis[x][y][pi] = 1;
			int le = level[x][y][pi];
			if(x == n-1 && y == m-1){
				cout<<"Case "<<++c<<": Luke and Leia can escape in "<<le<<" steps.\n";
				f = 1;
				break;
			}
			

			for(int idx = 0 ; idx<5;idx++){
				int ii = dx[idx] + x;
				int jj = dy[idx]+y;
				if(isv(ii , jj)&&!vis[ii][jj][(pi+1)%p]&&g[ii][jj][(pi+1)%p]!='1'){
					q.push(make_pair((pi+1)%p ,make_pair(ii , jj) ));
					level[ii][jj][(pi+1)%p] = le+1;
				}
			}

		}

		if(!f){
			cout<<"Case "<<++c<<": Luke and Leia cannot escape.\n";
		}
	}
	
	return 0;
}
