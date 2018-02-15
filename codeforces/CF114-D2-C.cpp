
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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
vector<string> v;
bool mas , fem;
string adj[]={"lios" , "liala"};
string non[]={"etr" , "etra"};
string vrb[]={"initis" , "inites"};
vector<int>sen;
void fun(string s){
	if(s.size() >= 4 && s.rfind(adj[0]) == s.size()-4 ){
			mas = 1;
			sen.push_back(0);
	}
	else if(s.size() >= 5 && s.rfind(adj[1]) == s.size()-5){
			fem = 1;
			sen.push_back(1);
	}
	else if(s.size() >= 3 && s.rfind(non[0]) == s.size()-3){
			mas = 1;
			sen.push_back(2);
	}
	else if(s.size() >= 4 && s.rfind(non[1]) == s.size()-4){
			fem = 1;
			sen.push_back(3);
	}
	else if(s.size() >= 6 && s.rfind(vrb[0]) == s.size()-6){
			mas = 1;
			sen.push_back(4);
	}
	else if(s.size() >= 6 && s.rfind(vrb[1]) == s.size()-6){
			fem = 1;
			sen.push_back(5);
	}else{
		fem = mas = 1;
	}
}
int main(){
	fast();string s;
	int n = 0;
	while(cin>>s){
		fun(s);
	}
	if( fem == mas ){
		cout<<"NO\n";
		return 0;
	}
	if(sen.size() == 1){
		cout<<"YES\n";
		return 0;
	}
	int idx = 0;
	while(idx< sen.size() && sen[idx] <= 1 ){
		idx++;
	}
	if(!(idx < sen.size() && sen[idx] <= 3)){
		cout<<"NO\n";
		return 0;
	}
	idx++;
	while(idx< sen.size() && sen[idx] <= 5 && sen[idx] > 3 ){
		idx++;
	}
	if(idx>= sen.size() ){
		cout<<"YES\n";
	}else {
		cout<<"NO\n";
	}
	return 0;
}
//mosta7il_
