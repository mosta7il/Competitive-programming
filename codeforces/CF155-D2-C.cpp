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
ll mem[100*1000+5][27];
string s;
int a[26][26];
int n;

ll rec(int idx, int prev){
        if(idx == s.size())
                return 0;
        ll &ret = mem[idx][prev];
        if(ret!=-1)return ret;
        ret = -OO;
        bool f = a[prev][s[idx]-'a'];
       
        if(!f){
                ret = max(ret , rec(idx+1 , s[idx]-'a')+1);
        }
        ret = max(ret , rec(idx+1 , prev));
        return ret;
}
int main(){
        clr(mem , -1);
	fast();
        cin>>s>>n;
        lp(i , n ) {
            char x,y;
            cin>>x>>y;
            a[x-'a'][y-'a']=a[y-'a'][x-'a'] =1;
        }
        ll mn = OO;
        lp(i , 26){
              mn = min(mn , s.size() -rec(0 , i) );
        }
        cout<<mn<<endl;
	return 0;
}
//mosta7il_
