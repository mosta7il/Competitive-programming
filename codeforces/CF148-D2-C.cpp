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
int n ,a,b;
vector<int> f ,s;
int main(){
	fast();
	cin>>n>>a>>b;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	if(a +1 ==n){
		cout<<-1<<endl;
		return 0;
	}
	int sum = 2 ,mx = 1 , d = n-b-a-1;
	cout<<1<<" " ;
	int last =0;
	for(int i = 1;i<n;i++){
		 if(b > 0){
			cout<<sum<<" ";
			mx=max(mx ,sum);
			b--;
			if(b)
				sum+=sum;
			last =1;
		}else if(d > 0){ 
			cout<<1<<" ";
			d--;	
		}else if(a > 0){
				cout<<mx+1<<" ";
				mx++;
			a--;
		}
		
	}
	
	return 0;
}
