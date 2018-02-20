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
string s;

int main(){
	fast();
	cin>>s;
	
	int hs  = 0, tot = 0;
	lp(i , s.size() ){
		if(s[i] =='(')
			tot++;
		else if(s[i] == ')')
			tot--;
		else hs++;
		if(tot < 0 ){
			cout<<-1<<endl;
			return 0;
		}
	}
	if(hs > tot){
		cout<<-1<<endl;
		return 0;
	}
	int tt = 0;
	vector<int>ans;
	lp(i , s.size() ){
			if(s[i] =='(')
			tt++;
		else if(s[i] == ')')
			tt--;
		else{
			if(hs == 1){
				ans.push_back(tot);
				tt-=tot;
			}else{
				ans.push_back(1);
				tot--;
				tt--;
			}
			hs--;
		}
		if(tt < 0){
			cout<<-1<<endl;
			return 0;
		}
	}
	lp(i , ans.size() ){
		cout<<ans[i]<<endl;
	}
	return 0;
}
//mosta7il_;
