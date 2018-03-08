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
const ll mod = 1000000007;
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
int n;
pair<int,int> legs[1000*100+6];
vector<int>d[201];
ll pre[1000*100+6];
int main(){
	fast();
        cin>>n;
        for(int i = 1 ; i<=n;i++)
                cin>>legs[i].first;
        for(int i = 1 ; i <= n ;i++)
                cin>>legs[i].second;
        sort(legs+1,legs+n+1);
        for(int i =1;i<=n;i++){
                d[legs[i].second].push_back(legs[i].first);
                pre[legs[i].first]++;
        }
        ll mn = 1e10;
        ll sum = 0;
        for(int i = 1 ; i <= 100*1000;i++){
                ll cur = pre[i];
                if(pre[i] <=  0)
                        continue;
                sum+=cur;
                ll tmp = 0;
                for(int j = 1 ; j <=200;j++){
                     
                      tmp+= (d[j].end() - upper_bound(d[j].begin() , d[j].end() , i))*j;
                }
                if(cur *2 > sum){
                        mn = min(tmp , mn);
                }else{
                        ll rem =sum - (cur * 2) +1;
                        
                        for(int j =1 ;j <=200;j++){
                              ll ans = (lower_bound(d[j].begin() , d[j].end() , i) - d[j].begin());
                                
                                ans= (min(rem , ans));
                                tmp += ans * j;
                                rem -= ans;
                                if(rem <= 0)
                                break;
                        }
                       mn = min(tmp , mn); 
                }
        }
        cout<<mn<<endl;
    	return 0;
}
