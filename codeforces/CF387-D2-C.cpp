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

string q , tot;
vector<string> arr;
void fun(){
	string tmp = "";tmp+=q[0];
	for(int i = 1 ; i < q.size();i++){
		if(q[i] != '0'){
			arr.push_back(tmp);
			tmp = "";
			tmp = q[i];
		}else tmp += q[i];
	}
	arr.push_back(tmp);
}
bool cmp ( string tot , string x ){

	if(tot.size() > x.size())
		return 1;
	else if( tot.size() < x.size() )
		return 0;
	else{
		for(int i = 0 ; i<x.size();i++){
			if(tot[i] > x[i])
				return 1;
			else if(tot[i] < x[i] )
				return 0;
		}
	}
	return 1;
}
int main(){
	fast();
	while(cin>>q){
		arr.clear();
		tot.clear();
	fun();
	ll cnt = 1;
	tot = arr[0];
	for(int i = 1;i<arr.size(); i++){
		if(cmp (tot , arr[i]) ){
			cnt++;
			
		}else{
			cnt = 1;
		}
		tot+=arr[i];
	}
	cout<<cnt<<endl;
	}
	return 0;
}
