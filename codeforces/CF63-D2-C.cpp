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
int n ;
vector< string > arr;

void gen(int i , string w){
	if(i == 4){
		arr.push_back(w);
		return ;
	}
	
	for(char idx = '0' ; idx<='9';idx++)
		gen(i+1 , w + idx);
}
bool fun(pair< string  , pair < int  ,int> > p , string s){
	set< char > ss;
	lp(i , s.size() )
		ss.insert(s[i]);

	if(ss.size() != 4)
		return 0;

	int in = 0 , nin = 0;
	for(int i = 0 ; i < s.size();i++){
		if(p.first[i] == s[i] ){
			in++;
		}else{
			nin+= (s.find(p.first[i] ) != -1);
		}
	}
	return (in == p.second.first && nin == p.second.second);
}
int main(){
	fast();
	gen(0 , "");
	while(cin>>n){
		pair< string  , pair < int  ,int> > a [11];
		string s ;
		int x , y ;
		vector<string>ans;
		lp(i, n){
			cin>>s>>x>>y;
			a[i] = MP(s , MP(x,y) );
		}
		lp(i , arr.size()){
			bool f = 0;
			lp(j , n){
				if(!fun(a[j] , arr[i]) ){
					f = 1;
					break;
				}
			}
			if(!f){
				ans.push_back(arr[i]);
			}
		}

		if(ans.size() == 0){
			cout<<"Incorrect data\n";
		}else if(ans.size() > 1){
			cout<<"Need more data\n";
		}else cout<<ans[0]<<endl;
	}

	return 0;
}
