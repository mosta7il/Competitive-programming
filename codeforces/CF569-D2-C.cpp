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
const int maax = 2*1000*1000+1;
bool p[maax];
int pi[maax];
int pal[maax];
void sieve(){
	p[1] =1;
	for(int i = 2;i*i<=maax;i++){
		if(!p[i])
			for(int j = i * i ;j<maax;j+=i)
				p[j]=1;
	}

}
int si;
void gen(int size , int num){
	if(size == 0){
		int tmp = num;
		if(si %2)
			tmp/=10;
		while(tmp ){
			num*=10;
			num+=(tmp%10);
			tmp/=10;
		}
		if(num < maax)
			pal[num]=1;
		return ;
	}
	if(size == 1){
		for(int idx = 0 ; idx<=9;idx++)
			gen(size-1 , num*10 + idx);
	}else{
		for(int idx = 0 ; idx<=9;idx++)
			gen(size-2 , num*10 + idx);
	}

}
int x,y;
int gcd(int a , int b){
	if(b == 0){
		return a;
	}
	return gcd(b , a%b);
}
int main(){
	fast();
	sieve();
	for(si=1;si<=7;si++){
		gen(si , 0);
	}
	pal[0]=0;
	for(int i = 1;i<maax;i++){
		pi[i] = pi[i-1] + (!p[i]);
		pal[i]+= pal[i-1];
	}
	cin>>x>>y;
	int w = gcd(x,y);
	x/=w;
	y/=w;
	for(int i = maax-1;i>=1;i--){
		if(pi[i]*y <= pal[i]*x){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"Palindromic tree is better than splay tree\n";

	return 0;
}
