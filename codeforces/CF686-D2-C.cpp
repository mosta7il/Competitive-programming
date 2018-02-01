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
int n , m;
string to7(int x){
	if(x == 0)
		return "0";
	string rs = "";
	while(x){
		int rm  = x % 7;
		x/=7;
		rs =  char(rm + '0')+rs;
	}
	return rs;
}
int to10(string x){
	int rt = 0 ;
	for(int i = 0 ; i < x.size();i++){
		rt+=(x[i]-'0');
		rt *=7;
	}
	return (rt / 7 );
}
int b[7]={0,1,2,3,4,5,6};
int main(){
	fast();

	cin>>n>>m;
	string x = to7(n-1) , y = to7(m-1);
	if(x.size() + y.size() > 7){
		cout<< 0 <<endl;
		return 0;
	}
	ll cnt = 0;
	map< pair<string , string> , int> mp;

	do{
		string hr = "" , min = "";
		for(int i = 0 ; i < x.size() ; i++){
			hr = hr +char(b[i]+48);
		}
		for(int i = x.size() ; i < (x.size() + y.size() ) ; i++){
			min += char(b[i]+48);
		}
		mp[MP(hr,min)]++;
		if( mp[MP(hr,min)] <= 1 && to10(hr) <= (n-1) && to10(min) <=(m-1) ){
			cnt++;
		}

	}while(next_permutation(b , b+7));

	
	
	cout<<cnt<<endl;
	return 0;
}
