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
long long n;

int main(){
	fast();
	cin>>n;
	long long mn = 1e18 , mx = -1e18;

	for(long long a = 1;a*a*a <= n ; a++){
		if(n % a == 0 )
		for(long long b = a;b*b <= (n/a);b++){
			if((n/a)%b == 0 ){
				long long c = n /a /b;
				mn = min(mn , ((a+2) * (b+2) * (c+1))-n);
				mx = max(mx , ((a+2) * (b+2) * (c+1))-n);
				mn = min(mn , ((a+2) * (b+1) * (c+2))-n);
				mx = max(mx , ((a+2) * (b+1) * (c+2))-n);
				mn = min(mn , ((a+1) * (b+2) * (c+2))-n);
				mx = max(mx , ((a+1) * (b+2) * (c+2))-n);
			}
		}
	}
	cout<<mn<<" "<<mx<<endl;
	return 0;
}
