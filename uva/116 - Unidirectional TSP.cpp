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
int n ,m;
int g[101][101];
long long mem[101][101];

long long rec(int i , int j){
	if(j == m){
		return 0;
	}

	long long &ret = mem[i][j];
	if(ret!= 1e17){
		return ret;
	}

	ret = min(ret , rec((i-1+n)%n , j+1)+g[i][j] );
	ret = min(ret , rec(i , j+1)+g[i][j]);
	ret = min(ret ,rec((i+1)%n , j+1)+g[i][j]);
	return ret;
}
void build(int i , int j){
	if(j == m){
		return;
	}
	cout<<i+1;
	if(j+1 != m)
		cout<<" ";
	long long ret , ret1 , ret2;
	ret = rec((i-1+n)%n , j+1)+g[i][j];
	ret1 =rec(i , j+1)+g[i][j];
	ret2 =rec((i+1)%n , j+1)+g[i][j];
	vector<int> ans;
	if(ret == min(ret , min(ret1 , ret2)))
		ans.push_back((i-1+n)%n);
	if(ret1 == min(ret , min(ret1 , ret2)))
		ans.push_back((i)%n);
	if(ret2 == min(ret , min(ret1 , ret2)))
		ans.push_back((i+1)%n);
	sort(ans.begin() , ans.end());

	if(ans[0] == (i-1+n)%n){
		build((i-1+n)%n , j+1);
	}else if(ans[0] == i){
		build(i , j+1);
	}else{
		build((i+1+n)%n , j+1);
	}
		
}
int main(){
	fast();
	
	while(cin>>n>>m){
		for(int i = 0 ; i < n ; i++)
			for(int j=0;j<m;j++)
				mem[i][j] = 1e17;

		for(int i = 0 ; i < n ; i++)
			for(int j=0;j<m;j++)cin>>g[i][j];

		long long ret = 1e17;
		int idx=-1;
		for(int i =0;i<n;i++){
			long long res = rec(i , 0);
			if(res < ret){
				idx = i;
				ret = res;
			}
			
		}
		build(idx , 0);
		cout<<endl;
		cout<<ret<<endl;
	}

	return 0;
}
