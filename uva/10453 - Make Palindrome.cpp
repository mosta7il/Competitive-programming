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
string s;
int mem[1001][1001];
int rec(int i , int j){
	
	if(i >= j)
		return 0;
	int &ret = mem[i][j];
	if(ret != -1)
		return ret;
	ret = 1001;
	if(s[i] == s[j]){
		ret = min (ret , rec(i+1 , j-1));
	}else{
		ret = min(ret , rec(i+1 , j) +1);
		ret = min(ret , rec(i , j-1) +1);
	}
	return ret;
}
string ans;
char add;
int cnt;
void build(int  i , int j){
	if(i >= j){
		if(i == j)
			add=s[i];
		return;
	}
	int ret , ret1 , ret2;
	if(s[i] == s[j]){
		ret = rec(i+1 , j-1);
		ans+=s[i];
		build(i+1 , j-1);
	}else{
		ret1 = rec(i+1 , j) +1;
		ret2 = rec(i , j-1) +1;
		if(ret1<=ret2){
			ans+=s[i];
			build(i+1, j);
		}else{
			ans+=s[j];
			build(i, j-1);
		}
	}


}
int main(){
	fast();
	
	while(cin>>s){
		for(int i = 0 ; i<1001;i++){
			for(int j = 0 ; j < 1001;j++){
				mem[i][j] = -1;
			}
		}
		ans = "";add='#';
		int ret = rec(0 , s.size()-1);
		build(0 , s.size()-1);
		if(add!='#')
			cout<<ret<<" "<<ans<<add;
		else cout<<ret<<" "<<ans;
		reverse(ans.begin() ,ans.end());
		cout<<ans<<endl;
		
	}

	return 0;
}
