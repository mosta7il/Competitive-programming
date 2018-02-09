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
int n;
int dic1[(int)1e5+1] , dic2[(int)1e5+1];
vector<int> a , b;
map<int , int> mp , mp1;
set<int>ans;
void pr(){
	cout<<ans.size()<<endl;
	for(auto i : ans){
		cout<<i<<" ";
	}
}
int main(){
	fast();
	cin>>n;
	if(n == 1){
		cout<<-1<<endl;
		return 0;
	}
	a.resize(n);
	b.resize(n);
	for(int i = 0 ; i < n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(a.begin() , a.end() );
	sort(b.rbegin() , b.rend() );
	if(n == 2){
		int lo = a[0] , hi = a[1];
		ans.insert(lo - (hi-lo));
		ans.insert(hi + (hi-lo));
		if((hi-lo)%2 == 0 ){
			ans.insert(lo + (hi-lo)/2);
		}
		pr();
		return 0;
	}
	for(int i = 0 ;i<n-1;i++){
		mp[a[i+1] - a[i]]++; 
		mp1[ b[i+1] - b[i]]++;
	}
	if(mp.size() <=2){
		if(mp.size() == 1){
			ans.insert(a[0] - (*mp.begin()).first);
			ans.insert( a[n-1] + (*mp.begin()).first);
		}else{
			map<int,int>::iterator it = mp.begin();
			it++;
			if((*mp.begin()).first * 2 == (*(it)).first && (*(it)).second == 1){
				for(int i = 0 ;i<n-1;i++){
					if(a[i+1] - a[i] == (*(it)).first){
						ans.insert(a[i]+ (*mp.begin()).first);
						break;
					}
				}
			}
		}
	}

	if(mp1.size() <=2){
		if(mp1.size() == 1){
			ans.insert(b[0] - (*mp1.begin()).first);
			ans.insert( b[n-1] + (*mp1.begin()).first);
		}else{
			map<int,int>::iterator it = mp1.begin();
			it++;
			if((*mp1.begin()).first * 2 == (*(it)).first && (*(it)).second == 1){
				for(int i = 0 ;i<n-1;i++){
					if( b[i+1] - b[i] == (*(it)).first){
						ans.insert(b[i]- (*mp1.begin()).first);
						break;
					}
				}
			}
		}
	}
	pr();

	return 0;
}
