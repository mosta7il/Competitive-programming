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
#include<cstring>
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


const ll OO = 1e9+10;
const ll mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif
	//std::ios_base::sync_with_stdio(0);
	//cin.tie(NULL);cout.tie(NULL);
}
int primefactors[5*1000*1000+1] , spf[5*1000*1000+2];

void sieve(){
	
	for(int i = 1 ; i <= 5 * 1000 * 1000 ; i++){
		spf[i] = i;
	}
	for (int i = 4; i<=5 * 1000 * 1000; i += 2)
		spf[i] = 2;
	for(int i = 3 ; i * i <= 5 *1000 * 1000 ; i++){
		if(spf[i] == i ){
			for(int j = i * i ; j<= 5 *1000*1000; j+=i)
				if(spf[j] == j)
					spf[j] = i;
		}
	}

}

int main(){
	fast();
	sieve();

	primefactors[1] = 0;
	for (int i = 2; i <= 5 * 1000 * 1000; i++){
		primefactors[i] = primefactors[i/spf[i]]+1;
	}
	for(int i = 2 ; i <= 5 * 1000 *1000 ; i++){
		primefactors[i] += primefactors[i-1] ;
	}
	
	int t;
	scanf("%d" , &t);
	while(t--){

		int a , b;
		scanf("%d %d" , &a , &b);
		printf("%d\n" ,primefactors[a] - primefactors[b]); 
	}
	return 0;
}
