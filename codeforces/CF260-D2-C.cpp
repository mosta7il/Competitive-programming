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

int n , x , mni;
ll boxes[100*1000+5];
int zeroi;
void printBoxes(){
	lp(i,n)
		cout<<boxes[i]<<" ";
	cout<<endl;
}

int main(){
	fast();
	
	while(cin>>n>>x){
		x--;
		ll mn = 1e9+5 , mni = -1;
		ll cnt = 0;
		lp(i,n){
			cin>>boxes[i];
			if(mn > boxes[i]){
				mn = boxes[i];
				mni = i;
			}
		}
		lp(i , n ){
			cnt+=mn;
			boxes[i] -=mn;
		}
		int idx = x ;
		while(boxes[idx]>0 ){
			boxes[idx]--;
			cnt++;
			idx = (idx - 1 + n)%n;
		}
		boxes[idx]+=cnt;
		printBoxes();
	}

	return 0;
}
