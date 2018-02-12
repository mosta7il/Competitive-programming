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
pair<int ,string>mem[1001][1001];
bool vis[1001][1001];

pair<int ,string> rec(int i , int j){

	pair<int ,string> &ret = mem[i][j];
	if(vis[i][j]){
		return ret;
	}
	vis[i][j] =1;

	if(i == j){
		return make_pair(1 , string (1 ,s[i]));
	}
	else if(i + 1 == j)
    {
        if(s[i] == s[j]) ret = make_pair(2, string(2, s[i]));
        else ret = make_pair(1, string(1, min(s[i], s[j])));
	}
	else if(s[i] == s[j]){
		ret = rec(i+1,j-1);
		ret.first+=2;
		ret.second=s[i] + ret.second+s[j];
	}else{
		pair<int ,string>left =rec(i+1,j)  ;
		pair<int,string> right = rec(i , j-1);
		if(left.first == right.first){
			ret = min(left , right);
		}else{
			ret = max(left , right);
		}
	}
	return ret;
}
pair<int,string> ans;

int main(){
	fast();
	
	while(cin>>s){
		memset(vis , 0 , sizeof vis);

		ans = rec(0 , s.size()-1);
		cout<<ans.second<<endl;
	}

	return 0;
}
