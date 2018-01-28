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
int xs[]={0 , 0 , 1, -1};
int ys[]={1,-1,0,0};
int m , n ;
int sx,sy , dx,dy;
char g[26][26];
int dist[26][26];
struct node{
	int tox , toy , w;
	node(int tx ,int  ty , int we){
		tox = tx , toy = ty , w =we;
	}
	bool operator < (const node& e)const{
		return w > e.w;
	}
};
bool isv(int i , int j){
	return (i <n&&i>=0&&j<m&&j>=0&& g[i][j]!='X'&&g[i][j]);
}

void di(){
	lp(i , 26)
		lp(j , 26) dist[i][j] =OO;
	priority_queue< node > p;
	p.push( node(sx , sy , 0) );
	dist[sx][sy] = 0;
	while(!p.empty() ){
		node cur = p.top();
		p.pop();

		if ( dist[cur.tox][cur.toy] < cur.w)
			continue;
		if(cur.tox == dx && cur.toy == dy)
			break;
		for(int dir = 0 ; dir <4;dir++){
			int ii = cur.tox + xs[dir] , jj = cur.toy + ys[dir];
			if(isv(ii , jj )){
				if( dist[ii][jj] > (g[ii][jj]-'0') + dist[cur.tox][cur.toy]){
					dist[ii][jj] = (g[ii][jj]-'0') + dist[cur.tox][cur.toy];
					p.push( node(ii , jj , dist[ii][jj] ) );
				}
			}
		}
	}

}
int main(){
	fast();

	while(cin>>m>>n&&n){
		
		lp(i,n)
			lp(j,m){
				cin>>g[i][j];
			if(g[i][j] =='S')
				sx=i , sy = j;
			if(g[i][j] =='D')
				dx=i , dy = j , g[i][j]='0';
		}
		di();
		cout<<dist[dx][dy]<<endl;
	}
	
	return 0;
}
