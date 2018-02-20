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

ll n , k;
string s;
void addtoz(string &z){
	int ca = 0;
	if(z[z.size()-1] =='9'){
			ca=1;
			z[z.size()-1] = '0';
	}else{
		z[z.size()-1]++;
		return;
	}
	for(int i = z.size()-2;i>=0;i--){
		if(z[i] =='9'){
			ca=1;
			z[i] = '0';
		}else{
			z[i]++;
			return ;
		}
	}
	z = '1'+z;
	return;
}
int main(){
	fast();
	cin>>n>>k;
	cin>>s;
	int idx = -1;
	string ww = s.substr(s.find("."));
	string zz = s.substr(0 , s.find(".") );
	for(int i = 1; i < ww.size();i++){
		if(ww[i] >='5'){
			idx=i;
			break;
		}
	}
	if(idx == -1){
		cout<<s<<endl;
		return 0;
	}
	bool cnt = 0;
	while(ww[idx]!='.' && k){
		if(cnt){
			ww[idx]++;
		}
		cnt = 0;
		if(ww[idx] >= '5'){
			cnt = 1;
			idx--;
			k--;
		}else{
			break;
		}
	}
	
	if(cnt){
		if(ww[idx]=='.'){
			addtoz(zz);
			cout<<zz;
		}else{
			ww[idx]++;
			cout<<zz;
			for(int i = 0;i<=idx;i++){
				cout<<ww[i];
			}
		}
	}else{
		cout<<zz;
		for(int i = idx;i>=0;i--){
				if(ww[i]!='0'){
					idx = i;
					break;
				}
		}
		if(idx >0)
		for(int i = 0;i<=idx;i++)
			cout<<ww[i];
	}
	
	return 0;
}
//mosta7il_;
