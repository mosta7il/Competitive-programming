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

int tri[201];

int fun(int x){
	int lo = 0 , hi =200;

	while(lo<=hi){
		int md = lo + (hi - lo +1)/2;
		if(tri[md] == x){
			return md;
		}else if(tri[md]>x)
			hi = md-1;
		else lo = md+1;
	}

	return -1;
}
struct triple{

	int b,c,d;
	triple(int x , int y , int z){
		b=x;
		c=y;d=z;
	}

};

vector< pair<int , triple> > ans;
bool cmp (pair<int , triple> i , pair<int , triple> j){
	if (i.first < j.first)
		return 1;
	if(i.first == j.first && i.second.b < j.second.b)
		return 1;
	if(i.first == j.first && i.second.b == j.second.b && i.second.c < j.second.c)
		return 1;
	return 0;
}
int main(){
	fast();

	lp(i , 201){
		tri[i]= (i*i*i);
	}
	for(int b = 2 ; b<=200;b++){
		for(int c = b ;c<=200;c++){
			for(int d = c;d<=200;d++){
				int a3 = (b*b*b)+(c*c*c)+(d*d*d);
				int idx = fun(a3);
				if(idx!=-1){
					triple tmp(b,c,d);
					ans.push_back(make_pair(idx , tmp));
				}
			}
		}
	}
	sort(all(ans),cmp);
	rep(i,ans){
		cout<<"Cube = "<<ans[i].first<<", Triple = ("<<ans[i].second.b<<","<<ans[i].second.c<<","<<ans[i].second.d<<")\n";
	}
	return 0;
}
