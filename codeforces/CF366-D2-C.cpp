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


const ll OO = 1e9+1;
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

int n , k;
int a[101] , b[101];
int mem[101][100001];
int rec(int i ,int t){
        if(i == n){
              if(t == 0)
                return 0;
              return -1e9;
        }
        int &ret = mem[i][t];
        if(ret!=-1)
        return ret;
       ret = -1e9;
        ret = max(ret , rec(i+1 ,t+a[i] - k*b[i])+a[i]);
        ret = max(ret , rec(i+1 , t));
        return  ret;
}
int main(){
	fast();
	clr(mem , -1);
        cin>>n >> k;
        lp(i , n)cin>>a[i];
        lp( i , n)cin>>b[i];
        int res = rec( 0 , 0  );
        if(res <= 0){
                cout<<-1<<endl;
        }else cout<<res<<endl;
	return 0;
}
//mosta7il_;
