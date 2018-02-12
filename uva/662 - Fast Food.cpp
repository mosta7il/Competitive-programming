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
int n ,k;
long long mem[202][202][31];
long long a[202];
long long pre[202][202];

int calc(int i , int j){
	long long mn = 1e9;
	if((j-i+1)%2 == 0){
		int p1 = (j+i)/2;
		int p2 = p1+1;
		mn = min(mn , pre[p1][j] - pre[p1][i-1]);
		mn = min(mn , pre[p2][j] - pre[p2][i-1]);

	}else{
		int p = (j+i)/2 ;
		mn = min(mn , pre[p][j] - pre[p][i-1]);
	}
	return mn;
}
long long rec(int start , int end , int cnt){
	if(cnt > k){
		return 1e10;
	}
	if(end == n+1){
		if(cnt!=k){
			return  1e10;
		}
		return 0;
	}
	long long &ret = mem[start][end][cnt];
	if(ret!=-1)
		return ret;
	ret = 1e9;
	
	if(end != n)
		ret = min(ret , rec(start , end+1 , cnt) );
	int tmp = calc(start , end);
	ret = min(ret , rec(end+1 , end+1 , cnt+1) + tmp);

	return ret;
}
void build(int start , int end , int cnt){
	if(cnt > k){
		return ;
	}
	if(end == n+1){
		
		return ;
	}
	long long ret = 1e9 , ret1 = 1e9;

	if(end != n)
		ret = rec(start , end+1 , cnt);
	int tmp = calc(start , end);
	ret1 = rec(end+1 , end+1 , cnt+1) + tmp;

	if(ret1 <= ret ){
		if((end-start+1)%2)
			cout<<"Depot "<<cnt+1<<" at restaurant "<<(start+end)/2;
		else{
			int p1 = (end+start)/2;
			int p2 = p1+1;
			if(pre[p1][end] - pre[p1][start-1] < pre[p2][end] - pre[p2][start-1]){
				cout<<"Depot "<<cnt+1<<" at restaurant "<<(p1);
			}else cout<<"Depot "<<cnt+1<<" at restaurant "<<p2;
		}
		if(start != end){
			cout<<" serves restaurants "<<start <<" to "<<end<<endl;
		}else cout<<" serves restaurant "<<start <<endl;
		build(end+1 , end+1 , cnt+1 );
	}else{
		build(start , end+1 , cnt);
	}
}
int main(){
	fast();
	int c = 0;
	while(cin>>n>>k&&n){
		cout<<"Chain "<<++c<<endl;
		for(int i = 1 ;i <= n;i++)
			cin>>a[i];
		for(int i = 1 ; i <= n ;i++){
			for(int j = 1 ; j <= n ;j++)
				pre[i][j] = pre[i][j-1] + abs(a[i]-a[j]);
		}

		memset(mem , -1 , sizeof mem);
		long long ret = rec(1,1,0);
		build(1,1,0);
		cout<<"Total distance sum = "<<ret<<endl<<endl;;
	}

	return 0;
}
