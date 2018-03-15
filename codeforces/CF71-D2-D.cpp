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
int n , m;
string a[17][17];
map< string  , bool> vis;
int dist(int i , int j , int x , int y){

	return ((x-i)*(x-i) + (j - y)* (j-y));
}
pair<int , int>  can(pair<int , int> x){

	for(int i = 0 ; i <= n-3;i++){
		for(int j = 0 ; j <= m-3;j++){
			if(dist(i , j , x.first , x.second )< 9){
				continue;
			}
			set<char> s , ss;
			for(int w = i;w<i+3;w++){
				for(int y = j;y<j+3;y++){
					s.insert(a[w][y][0]);
					ss.insert(a[w][y][1]);
				}
			}
			if(s.size() == 9 || ss.size() == 1){
				return MP(i , j);
			}
		}
	}
	return MP(-1 , -1);
}
int main(){
	fast();
	string rank = "A23456789JTKQ" , suit = "CDHS";
	for(int i = 0 ; i <rank.size();i++){
		for(int j = 0 ; j < suit.size();j++){
			vis[string(1,rank[i])+string(1 , suit[j])] = 0;
		}
	}
	vis["J1"] = vis["J2"] = 0;

	cin>>n>>m;
	for(int i = 0 ; i < n;i++){
		for(int j = 0 ; j <m;j++){
			cin>>a[i][j];
			vis[a[i][j]]=1;
		}
	}
	vector<string>v;vector< pair<int , int> > vv;
	for(auto i : vis){
		if(!i.second){
			if(!(i.first == "J1" || i.first == "J2"))
				v.push_back(i.first);
		}	
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j<m;j++){
			if(a[i][j] == "J1" || a[i][j] == "J2")
				vv.push_back( MP(i , j) );
		}
	}
	
	if( vv.size() == 1){
		for(int i = 0 ; i<v.size();i++){
			string tmp = a[ vv[0].first] [ vv[0].second ];
			a[vv[0].first][vv[0].second] = v[i];
			pair<int , int>bb , aa = can(MP(-10 , -10));
			if(aa != MP(-1 , -1) ){
				bb = can(aa);
				if(bb!= MP(-1 , -1) ){
					cout<<"Solution exists.\n";
					cout<<"Replace "<<tmp<<" with "<<v[i]<<".\n";
					cout<<"Put the first square to "<<"("<<aa.first+1<<", "<<aa.second+1<<").\n";
					cout<<"Put the second square to "<<"("<<bb.first+1<<", "<<bb.second+1<<").\n";
					return 0;
				}
			}
			a[vv[0].first][vv[0].second] = tmp;
		}

		cout<<"No solution.\n";
		return 0;
	}else if( vv.size() == 2){
		for(int i = 0 ; i <v.size();i++){
			for(int j = 0 ; j < v.size();j++){
				if(i == j)continue;
				string tmp1 = a[ vv[0].first] [ vv[0].second ] , tmp2= a[ vv[1].first] [ vv[1].second ];
				a[ vv[0].first] [ vv[0].second ]  = v[i];
				a[ vv[1].first] [ vv[1].second ]  = v[j];
				pair<int , int>bb , aa = can(MP(-10 , -10));
				if(aa != MP(-1 , -1) ){
					bb = can(aa);
					if(bb!= MP(-1 , -1) ){
						cout<<"Solution exists.\n";
						cout<<"Replace "<<((tmp1 == "J1")?tmp1:tmp2)<<" with "<<((tmp1 == "J1")?v[i]:v[j])<<" and "<<((tmp1 == "J2")?tmp1:tmp2)<<" with "<<((tmp1 == "J2")?v[i]:v[j])<<".\n";
						cout<<"Put the first square to "<<"("<<aa.first+1<<", "<<aa.second+1<<").\n";
						cout<<"Put the second square to "<<"("<<bb.first+1<<", "<<bb.second+1<<").\n";
						return 0;
					}
				}
				a[vv[0].first][vv[0].second] = tmp1 , a[vv[1].first][vv[1].second] = tmp2;			}
		}
		cout<<"No solution.\n";
		return 0;
	}else{
		pair<int , int>bb , aa = can(MP(-10 , -10));
				if(aa != MP(-1 , -1) ){
					bb = can(aa);
					if(bb!= MP(-1 , -1) ){
						cout<<"Solution exists.\n";
						cout<<"There are no jokers.\n";
						cout<<"Put the first square to "<<"("<<aa.first+1<<", "<<aa.second+1<<").\n";
						cout<<"Put the second square to "<<"("<<bb.first+1<<", "<<bb.second+1<<").\n";
						return 0;
					}
			}
		cout<<"No solution.\n";
		return 0;
	}
	return 0;
}
