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
const ll mod = 1e9 + 7;
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

string dp[1001];
string add(string a , string b){
        while(a.size() < b.size()){
                a = "0" + a;
        }
        while(b.size() < a.size()){
                b = "0" + b;
        }
        int ca = 0;
        string ret(a.size(),'0');
        for(int i = a.size()-1;i>=0;i--){
                int rs = (a[i] - '0') + (b[i]-'0')+ ca;
               ca = rs / 10;
               rs%=10;
               ret[i] = char(rs+'0');
        }
       if(ca>0){
               ret = "1" + ret;
       }
       return ret;
}
int main(){
	fast();
	lp(i , 1001)
	        dp[i] = "0";
	dp[1] = "2";
	dp[2] = dp[3] = "1";
        for(int i = 2 ; i <= 1000 ; i++){
                dp[i] = add(dp[i] , dp[i-1]);
                dp[i] = add(dp[i] , dp[i-1]);
                if(i - 2 > 0){
                dp[i] = add(dp[i] , dp[i-2]);                
                }
                if(i - 3 > 0){
                dp[i] = add(dp[i] , dp[i-3]);        
                }
        }
        int n;
        while(cin>>n){
                bool f = 0;
                for(int i=0;i<dp[n].size();i++){
                        if(dp[n][i] == '0'&& !f)
                        continue;
                        else {
                        f =1;
                        cout<<dp[n][i];
                        }
                }
                cout<<endl;
        }
	return 0;
}
