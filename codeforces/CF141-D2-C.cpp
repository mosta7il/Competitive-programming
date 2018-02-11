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

const long long mod = 1e9+7;

void fast(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;
vector< pair<int ,string> > dic;
pair<int ,string> a[3001];

int main(){
	fast();
	cin>>n;
	string c ;int u;
	for(int i = 0 ; i < n ; i++){
		cin>>c>>u;
		a[i] = make_pair(u , c);
	}
	sort(a , a+n);
	
	int hi = 3001  , md;
	for(int i = 0 ; i < n;i++){
		if(a[i].first > i){
			cout<<-1<<endl;
			return 0;
		}
		dic.insert(dic.begin()+a[i].first , make_pair( hi-i,a[i].second));
	}
	for(int i = 0 ; i<n;i++){
		
		cout<<dic[i].second<<" "<<dic[i].first<<endl;
	}
	return 0;
}
