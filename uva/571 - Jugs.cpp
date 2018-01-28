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
int a,b,n;
bool vis[1001][1001];
struct state{
	int cura , curb;
	vector<string> path;
	state(int a , int b , vector<string> & s){
		path.clear();
		cura = a;
		curb = b;
		for(int i = 0 ; i <s.size();i++)
			path.push_back(s[i]);
	}
};

int main(){
	fast();

	while(cin>>a>>b>>n){
		clr(vis,0);
		vector<string>s;
		state init(0 , 0 ,s);
		queue< state > q;
		q.push(init);
		while(!q.empty()){
			state cur = q.front();
			q.pop();
			vis[cur.cura][cur.curb] = 1;
			if(cur.curb == n){
				for(int i = 0 ; i < cur.path.size();i++)
					cout<<cur.path[i]<<endl;
				cout<<"success\n";
				break;
			}
			if(!vis[a][cur.curb]&&cur.cura < a){
			//fill A
			cur.path.push_back("fill A");
			q.push( state(a , cur.curb , cur.path) );
			cur.path.pop_back();
			}
			if(!vis[cur.cura][b]&&cur.curb < b){
			//fill B
			cur.path.push_back("fill B");
			q.push( state(cur.cura , b , cur.path) );
			cur.path.pop_back();
			}
			if(!vis[0][cur.curb]&&cur.cura > 0){
			//empty A
			cur.path.push_back("empty A");
			q.push( state(0 , cur.curb , cur.path) );
			cur.path.pop_back();
			}
			if(!vis[cur.cura][0]&&cur.curb > 0){
			//empty B
			cur.path.push_back("empty B");
			q.push( state(cur.cura , 0 , cur.path) );
			cur.path.pop_back();
			}
			int d = min(b , cur.curb + cur.cura) - cur.curb;
			if(!vis[cur.cura-d][min(b , cur.curb + cur.cura)]&&cur.curb < b && cur.cura > 0 ){
			//pour A B
			cur.path.push_back("pour A B");
			
			q.push( state(cur.cura-d , min(b , cur.curb + cur.cura) , cur.path) );
			cur.path.pop_back();
			}
			 d = min(a , cur.curb + cur.cura) - cur.cura;

			if(!vis[min(a , cur.curb + cur.cura)][ cur.curb - d]&&cur.cura < a && cur.curb > 0 ){
			//pour B A
			cur.path.push_back("pour B A");
			 q.push( state(min(a , cur.curb + cur.cura), cur.curb - d , cur.path) );
			cur.path.pop_back();
			}
		}
	}
	
	return 0;
}
