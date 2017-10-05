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
vector<int>v;
ll mem[10001][10001];
ll rec(int i, int l){
	if (i == v.size()-1){
		return 0;
	}
	if (mem[i][l] != -1)return mem[i][l];
	ll ret = rec(i + 1, l);
	if (v[l] < v[i])
		ret = max(ret, rec(i + 1, i) + 1);

	return mem[i][l] = ret;
}

void build(int i, int l){
	if (i == v.size() - 1){
		return ;
	}

	ll ret = rec(i + 1, l);
	ll res = 0;
	if (v[l] < v[i])
		res = max(res, rec(i + 1, i) + 1);
	if (res > ret){
		cout << v[i] << endl;
		build(i + 1, i);
	}
	else{
		build(i + 1, l);
	}
}
int main(){
	fast();
	int t; cin >> t;
	
	cin.ignore(); cin.ignore();
	while (t-- ){
		clr(mem, 0);
		v.clear();
		string s;
		while (getline(cin, s) && s != ""){
			stringstream ss;
			ss << s;
			int x; ss >> x;
			v.push_back(x);
		}
		v.push_back(-1);
		cout << "Max hits: " << rec(0, v.size() - 1) << endl;
		build(0, v.size() - 1);
		if (t)cout << endl;
	}

	return 0;
}
//mosta7il_
