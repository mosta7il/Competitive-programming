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
map<string  , int> mp;
vector < pair< int , pair<int , pair<int , string> > > >tab; 

void ins(string t , int g , int gg){
	if(mp.find( t) == mp.end()){
			tab.push_back( MP((g>gg)?3:(g==gg)?1:0 , MP((g-gg) , MP(g , t))) );
	}else{
		for(int i = 0 ; i < tab.size() ; i++){
			if(tab[i].second.second.second == t){
				tab[i].first += (g > gg )?3:(g==gg)?1:0;
				tab[i].second.first += (g - gg);
				tab[i].second.second.first += g;
				break;
			}
		}
	}
	mp[t]++;
}

bool cmp(pair< int , pair<int , pair<int , string> > > i , pair< int , pair<int , pair<int , string> > > j ){
	if( i .first > j.first )
		return 1;
	if(i.first == j .first && i.second.first > j.second.first)return 1;
	if(i.first == j .first && i.second.first == j.second.first&& i.second.second.first > j.second.second.first)
		return 1;
	if(i.first == j .first && i.second.first == j.second.first&& i.second.second.first == j.second.second.first && i.second.second.second < j.second.second.second)
		return 1;
	return 0;


}
int main(){
	fast();
	lp(i , 5){
		string t , tt ;
		int g ,gg;
		cin>>t>>tt;
		cin>>g;cin.ignore();cin>>gg;
		ins(t , g , gg);
		ins(tt , gg , g);
	}
	sort(all(tab) , cmp);
	int idx = -1 , idx1 = -1;string w;
	for(auto i : mp){
		if(i.second == 2&&i.first !="BERLAND"){
			w = i.first;
			break;
		}
	}
	for(int i = 0 ; i < tab.size() ; i++){
		if(tab[i].second.second.second == "BERLAND"){
			idx = i;
			
		}else if(tab[i].second.second.second == w){
			idx1 = i;
		}
	}

	if(idx <=1){
		cout<<"1:0"<<endl;
		return 0;
	}
	if(tab[1].first > tab[idx].first+3){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}else if(tab[1].first < tab[idx].first+3){
		cout<<"1:0"<<endl;
		return 0;
	}

	if(tab[idx].second.first >= tab[1].second.first ){
		cout<<"1:0"<<endl;
		return 0;
	}
	int x , y ;
	x = y = 0;
	x++;
	tab[idx].first +=3;tab[idx].second.first++;tab[idx].second.second.first++;
	tab[idx1].second.first -=1;
	sort(all(tab) , cmp);
	for(int i = 0 ; i < tab.size() ; i++){
		if(tab[i].second.second.second == "BERLAND"){
			idx = i;
			
		}else if(tab[i].second.second.second == w){
			idx1 = i;
		}
	}
	while(tab[idx].second.first < tab[1].second.first){
		x++;
		tab[idx].second.first++;tab[idx].second.second.first++;
		tab[idx1].second.first -=1;
		sort(all(tab) , cmp);
		for(int i = 0 ; i < tab.size() ; i++){
			if(tab[i].second.second.second == "BERLAND"){
				idx = i;
			
			}else if(tab[i].second.second.second == w){
				idx1 = i;
			}
		}
	}
	while(idx > 1){
		if(idx1 == 1){
			x++;
			tab[idx].second.first++;tab[idx].second.second.first++;
			tab[idx1].second.first -=1;
		}else{
			x++ , y++;
			tab[idx].second.second.first++;
		}
		sort(all(tab) , cmp);
		for(int i = 0 ; i < tab.size() ; i++){
			if(tab[i].second.second.second == "BERLAND"){
				idx = i;
			
			}else if(tab[i].second.second.second == w){
				idx1 = i;
			}
		}
	}
	cout<<x <<":"<<y<<endl;
	return 0;
}
//mosta7il_;
