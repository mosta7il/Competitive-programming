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
ll ax,ay , bx,by , tx,ty;
int n;
ld a[100001] , b[100001] , c[100001];
ll x , y;
ld dist(ll xx , ll yy ,ll zz ,ll tt){
        return sqrt(1.0 * (xx-zz) * (xx-zz) + 1.0 * ( yy - tt)* (yy - tt));
}
ld mem[100001][3][3];
bool vis[100001][3][3];
ld rec(int idx , bool af ,bool bf){
        if(idx == n){
                if(af || bf){
                        return 0;
                }else return 1e16;
        }
        if(vis[idx][af][bf])
        return mem[idx][af][bf];
        vis[idx][af][bf]=1;
        ld ret = 1e16;
        if(!af){
               ret = min(ret , rec(idx+1 , 1 , bf)+a[idx] + c[idx]); 
        }
        if(!bf){
                ret =min(ret , rec(idx+1 , af , 1)+b[idx]+c[idx]);
        }
       ret = min(ret , rec(idx+1 , af,bf)+c[idx] + c[idx]);
       return mem[idx][af][bf] = ret;
}
int main(){
	fast();
cin>>ax>>ay>>bx>>by>>tx>>ty>>n;
lp(i , n){
 cin>>x>>y;
a[i] = dist(ax , ay , x , y);
b[i] = dist(bx,by , x , y);
c[i] = dist(tx,ty , x, y);
}
cout<<fixed<<setprecision(7)<<rec(0 , 0 , 0)<<endl;
	return 0;
}
