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
int n , h;
int fish[26] , d[26] , t[26];
int mem[26][1001];
int calc(int i,int t){
	if(t == 0)
		return 0;
	int rs = fish[i],sum ;
	sum=rs;
	t--;
	while(t--){
		sum += max(0,(rs - (d[i] ))) ;
		rs-=d[i];
	}
	return sum;
}
int rec(int i , int time){
	if(time < 0)
		return -1e9;
	if(time == 0)
		return 0;
	if(i == n){
		return 0;
	}
	int &ret = mem[i][time];
	if(ret!=-1)
		return ret;
	ret = 0;
	for(int idx = (time /5) ; idx >=0  ;idx--){
		if(i == n-1)
			ret = max(ret ,rec(i+1 , time - (idx * 5))+calc(i ,idx));
		else{ 
			int rs =  time-(idx *5);
			if(rs - t[i]*5 >=0 )
				ret = max(ret ,rec(i+1 ,rs - t[i]*5)+calc(i ,idx));
			else if(rs == 0) ret = max(ret , rec(i+1, rs)+calc(i ,idx));
		}
	}
	return ret;
}
vector<int> ans;

void build(int i , int time){
	if(time < 0)
		return ;
	if(time == 0)
		return ;
	if(i == n){
		return ;
	}
	int ret ,ret1 , ret2;
	ret = ret1 = ret2 = 0;
	for(int idx = (time /5) ; idx >=0  ;idx--){
		if(i == n-1){
			if( rec(i+1 , time - (idx * 5))+calc(i ,idx) == mem[i][time] ){
				ans[i] = idx* 5;
				build(i+1 , time - (idx * 5));
			}
		}else{ 
			int rs =  time-(idx *5);
			if(rs - t[i]*5 >=0 ){
				if( rec(i+1 ,rs - t[i]*5)+calc(i ,idx) == mem[i][time]){
					ans[i] = idx*5 ;
					build(i+1 , rs - t[i]*5);
					return;
				}
			}else if(rs == 0){ 
				if(mem[i][time] == rec(i+1, rs)+calc(i ,idx)){
					ans[i] = idx*5 ;
					build(i+1 , rs);
					return;
				}
			}
		}
	}
	return ;
}
int main(){
	fast();
	int c = 0;
	while(cin>>n&&n){
		if(c )
			cout<<endl;
		c++;
		memset(mem , -1 , sizeof mem);
		cin>>h;
		h *=60;

		for(int i = 0 ; i<n;i++)
			cin>>fish[i];
		for(int i = 0 ; i<n;i++)
			cin>>d[i];
		for(int i = 0 ; i<n-1;i++)
			cin>>t[i];
		ans.clear();
		ans.resize(n , 0);
		int ret = rec(0 , h);
		build(0 , h);
		for(int i = 0; i <n-1;i++)
			cout<<ans[i]<<", ";
		cout<<ans[n-1]<<endl;
		
		cout<<"Number of fish expected: "<<ret<<endl;
	}

	return 0;
}
