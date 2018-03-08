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
const ll mod = 1e9 + 7;
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
int n , m;
char g[16][101];
ll lastR[16] , lastL[16] , cnt[16];
ll mn ;
void rec(int idx , int stair , ll cost ){
	if(idx == n-1){
		if(stair){
			mn = min(mn , cost + lastR[n - idx  - 1]);
		}else{
			mn = min(mn , cost + lastL[n - idx  - 1]);
		}
		return ;
	}
	if(cnt[n-1] - cnt[idx] == 0 ){
			if(stair)mn = min(mn , cost + lastR[n - idx  - 1]);
			else mn = min(mn , cost + lastL[n - idx  - 1]);
			return ;
	}
	if(stair){
		
			rec(idx+1 , 1 , cost+ 2* lastR[n - idx  - 1] +1);
			rec(idx+1 , 0 , cost+ m+2);

	}else{
			rec(idx+1 , 1 , cost+m +2) ;
			rec(idx+1 , 0 , cost+2 * lastL[n - idx  - 1 ] +1);
	}
}
int main(){
	fast();
	cin>>n>>m;
	mn = LLONG_MAX;
	for(int i = 0 ; i< n; i++){
		bool f = 0;
		for(int j =0;j<m+2;j++){
			cin>>g[i][j];
			if(g[i][j] == '1'){
				cnt[n - i - 1]++;
				lastL[i] = j;
			}
			if(!f && g[i][j] =='1'){
				f=1;
				lastR[i]=(m+2) - j - 1;
			}
		}
	}
	for(int i = 0 ; i < n ;i++){
		if(i)cnt[i]+=cnt[i-1];
	}
	rec(0 , 0 , 0);
	cout<<mn<<endl;
	return 0;
}
