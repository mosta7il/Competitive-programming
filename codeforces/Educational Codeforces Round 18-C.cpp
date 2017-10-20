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
string s;
int cnt;
int mem[100 * 1000 + 1][4][3];
int rec(int i,int cnt, bool flag){
	if (i == s.size()){
		if (flag == 0)return 1e9;
		if (cnt % 3 == 0){
			return 0;
		}
		return 1e9;
	}
	if (mem[i][cnt][flag]!=-1)return mem[i][cnt][flag];
	int ret = 1e9;
	if (flag == 0 && s[i] == '0'&&i+1<s.size()){}
	else 	ret = min(ret, rec(i + 1, (cnt + s[i] - '0') % 3 , 1));
	 ret = min(ret, rec(i + 1, cnt, flag) + 1); 
	return mem[i][cnt][flag] = ret;
}
vector<char>vv;
void build(int i, int cnt ,bool flag){
	if (i == s.size()){
		
		return ;
	}
	
	int ret1 = 1e9 ,ret2 = 1e9;
	if (flag == 0 && s[i] == '0'&&i+1<s.size()){}
	else	ret1 = min(ret1, rec(i + 1, (cnt + s[i] - '0') % 3, 1));
	ret2 = min(ret2, rec(i + 1, cnt, flag) + 1);
	if (ret1 < ret2){
		vv.push_back(s[i]);
		build(i + 1, (cnt + s[i] - '0') % 3 ,1) ;
	}
	else{
		build(i + 1, cnt ,flag);
	}
	
}
int main(){
	fast();
	clr(mem, -1);
	cin >> s;
	int z = 0;
	lp(i, s.size())z += s[i] == '0';
	int res=rec(0, 0 , 0);
	build(0, 0 , 0);
	bool f = 0;
	if (res >= 1e9){
		if (z>0)
			cout << 0 << endl;
		else cout << -1 << endl;
	}
	else{
		lp(i, vv.size()){
			if (vv[i] == '0'&&!f)continue;
			cout << vv[i];
			f = 1;
		}
		if (!f)cout << 0 << endl;
	}
	return 0;
}
//mosta7il_
