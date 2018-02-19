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
int n , p;

string s;
string mn;
bool valid(string st , int i , char x ){
	if(i-1 < 0 )
		return 1;
	if(x == st[i-1])
		return 0;
	if(i-2<0)
		return 1;
	if(x == st[i-2])
		return 0;
	return 1;
}
int main(){
	fast();
	cin>>n>>p;
	cin>>s;
	mn = "{";
	for(int i = s.size()-1;i>=0;i--){
		string tmp = s;
		bool f = 0 , end = 0;
		for(int j = i;j<s.size();j++){
			end = 0;
			if(!f){
				for(char x = tmp[j]+1;x< p+'a';x++){
					if( valid(tmp , j , x) ){
						tmp[j] =x; 
						end =1;
						break;
					}
				}
				f =1;
			}else{
				for(char x ='a';x< p+'a';x++){
					if( valid(tmp , j , x) ){
						tmp[j] =x; 
						end =1;
						break;
					}
				}
			}
			if(!end)
				break;
		}
		if(end && tmp > s)
			mn = min(tmp , mn);
	}
	if(mn =="{")
		cout<<"NO"<<endl;
	else cout<<mn<<endl;
	return 0;
}
//mosta7il_;
