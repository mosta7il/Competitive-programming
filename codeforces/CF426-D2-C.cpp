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
int n , k;
int a[201];
int mx;
int main(){
	fast();
	cin>>n>>k;
	
	for(int i = 0 ; i < n ; i++)cin>>a[i];
	mx =-1e9;
	for(int i = 0;i<n;i++){
		for(int si = 1;si<=n-i;si++){
			vector<int> in , out;
			int sum = 0;
			int l = i , r = i+si-1;
			for(int j = 0 ; j < n;j++){
				if(j>=l&&j<=r){
					in.push_back(a[j]);
					sum+=a[j];
				}
				else out.push_back(a[j]);
				
			}
			sort(in.begin() , in.end());
			sort(out.rbegin() , out.rend() );
			int idx = 0 , cnt = 0;
			while(idx < out.size() && idx < in.size() && cnt <k){
				if( sum- in[idx] + out[idx] < sum){
					break;
				}
				cnt++;
				sum= sum-in[idx] + out[idx];
				idx++;
			}
			mx = max(mx , sum);
		}
	}
	cout<<mx<<endl;
	return 0;
}
