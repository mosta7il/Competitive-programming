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
const ll mod = 1000000007;
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
ll n , m , t;
vector<pair<int,ll> > g[5001];
ll mem[5001][5001];
ll rec(int i , int j){
        if(j < 1)
        return 1e10;
        if(i == n){
                if(j ==1)return 0;
                return 1e10;
        }
        ll &ret = mem[i][j];
        if(ret != -1)
        return ret;
        ret = 1e10;
        for(auto no : g[i]){
                ret = min(ret , rec(no.first , j-1)+no.second);
        }
        return ret;
}
void build(int i , int j){
          if(i == n){
                return ;
        }
       
        for(auto no : g[i]){
                if(mem[i][j] == (rec(no.first , j-1)+no.second)){
                        cout<<no.first<<" ";
                        build(no.first , j-1);
                        return;
                }
        }
        return ;
}
int main(){
	fast();
	clr(mem , -1);
        cin>>n>>m>>t;
        lp( i ,m){
           int u , v , w;cin>>u>>v>>w;
           g[u].push_back({v , w});
        }
   int mx =0;
   for(int i = 1;i<=n;i++){
           if(rec(1 , i) <= t){
                   mx = i;
           }
     }
     cout<<mx<<endl<<1<<" ";
     build(1 , mx);
	return 0;
}
