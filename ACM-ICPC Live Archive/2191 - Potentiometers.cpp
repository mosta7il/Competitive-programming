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


const ll OO = 1e11;
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
int n;
int tree[20*(2*1000*100 + 2)];
int a[200 * 1000 + 2];

void build(int cur  , int lo , int hi){
	if(lo == hi){
		tree[cur] = a[hi];
		return ;
	}

	int md = lo + (hi - lo) /2;
	int left = cur * 2;
	int right = cur  *2 + 1;
	build(left , lo , md);build(right , md+1 , hi);
	tree[cur] = tree[left] + tree[right];
}
void update(int idx , int val ,int cur , int lo , int hi ){

	if(lo == hi){
		tree[cur] = val;
		return;
	}
	int md = lo + (hi - lo) /2;
	int left = cur * 2;
	int right = cur  *2 + 1;
	if(idx <= md ){
		update(idx , val , left , lo , md);
	}else{
		update(idx , val ,right , md+1 , hi);
	}
	tree[cur] = tree[left] + tree[right];
}

int query(int x , int y , int cur , int lo , int hi){
	if(x <= lo && y >= hi){
		return tree[cur];
	}
	if(hi < x ||lo > y){
		return 0;
	}
	int md = lo + (hi - lo) /2;
	int left = cur * 2;
	int right = cur  *2 + 1;
	return query(x , y , left , lo , md) + query(x , y , right , md+1 , hi);
}
int main(){
	fast();
	int idx = 1;
	while(cin>>n&&n){
		if(idx > 1)
			cout<<endl;
		cout<<"Case "<<idx++<<":"<<endl;
		fill(tree , tree + 20*(2*1000*100 + 2) , 0);
		string s;
		for(int i = 1;i<=n;i++)
			cin>>a[i];
		build(1 , 1 , n);
		cin.ignore();
		while(getline(cin , s) && s != "END"){
			stringstream ss;ss<<s;
			char ch;int x ,y;
			ss>>ch;ss>>x>>y;
			if(s[0] == 'S'){
				update(x , y , 1 , 1 , n);
			}else{
				cout<<query(x , y , 1 , 1 , n)<<endl;
			}
		}
		
	}
	return 0;
}
