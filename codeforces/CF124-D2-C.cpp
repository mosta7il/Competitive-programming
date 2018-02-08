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



void fast(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

string s;
set<int> g[1001];
vector< pair<int ,char> > a;
int al[26];
bool isp(int x){
	if(x==1)return 0;
	if(x==2)return 1;
	if(x%2 == 0)return 0;
	for(int i = 2;i*i<=x;i++)
		if(x%i == 0)
			return 0;
	return 1;
}
int main(){
	fast();

	while(cin>>s){
		for(int i = 0 ; i <s.size();i++){
			al[ s[i]-'a' ]++;
		}
		for(int i = 0 ; i <26;i++){
			if(al[i]>0)
			a.push_back( make_pair( al[i] , i+'a'));
		}
		sort(a.rbegin() , a.rend() );
		for(int i = 2;i<=s.size();i++){ //p
			if(isp(i)){
				int u = s.size() / i;
				if(u >= 2)
					for(int w = 1;w<= u;w++){ //i
						g[2].insert(w*i);
					}
				else if(u >=1) g[i].insert(i);
			}
		}
		bool f = 0;int idx=0;
		vector<char> v(s.size() +1,'#');
		for(int i = 1;i<1001;i++){
			if(g[i].size() > a[idx].first){
				f=1;break;
			}
			for(auto i : g[i])
				v[i]= a[idx].second;
			a[idx].first-=g[i].size();
			al[ a[idx].second-'a']-=g[i].size();
			if(a[idx].first<=0)
				a.erase(a.begin());
			sort(a.rbegin(),a.rend());
		}
		if(f){
			cout<<"NO\n";
			return 0;
		}else{

			for(int i = 1 ; i<= s.size();i++){
				if(v[i] == '#'){
					bool tt = 0;
					for(int j = 0 ; j < 26;j++){
						if(al[j] > 0 ){
							v[i] = j+'a';
							al[j]--;
							tt=1;
							break;
						}
					}
					if(!tt){
						cout<<"NO\n";
						return 0;
					}
				}
			}
			cout<<"YES\n";
			for(int i = 1;i<=s.size();i++)
				cout<<v[i];
		}
	}
	return 0;
}
