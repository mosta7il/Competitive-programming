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
int n , u;
map<int , int> mp;
string s;
vector< pair<string , int> > ans;
int main(){
	fast();
	cin>>n;

	for(int i = 0 ; i < n;i++){
		cin>>s;
		if(s == "insert"){
			cin>>u;
			mp[u]++;
		}else if(s =="getMin"){
			cin>>u;
			while(mp.size() > 0 && (*mp.begin()).first < u){
				int d = mp[(*mp.begin()).first];
				for(int x = 0 ; x<d;x++)
					ans.push_back(make_pair("removeMin" , u) );
				mp.erase((*mp.begin()).first);
			}
			if(mp.size()==0){
				mp[u]++;
				ans.push_back(make_pair("insert" , u));
			}else if(mp.size() > 0 && (*mp.begin()).first != u){
				mp[u]++;
				ans.push_back(make_pair("insert" , u));
			}
		}else{
			if(mp.size()> 0 ){
				mp[(*mp.begin()).first]--;
				if(mp[(*mp.begin()).first] == 0)
					mp.erase((*mp.begin()).first);
			}else{
				ans.push_back(make_pair("insert" , 1));
			}
		}
		ans.push_back( make_pair(s , u) );
	}
	cout<<ans.size()<<endl;
	for(int i = 0 ;i <ans.size();i++){
		if(ans[i].first != "removeMin")
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
		else cout<<ans[i].first<<endl;
	}
	return 0;
}
