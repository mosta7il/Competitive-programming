/*
	

*/

// Defualt Block
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e9
#define mod 1e9+7
#define EPS 1e-8
#define MLOG 30
#define MAX 20 * 1000 * 1000+5

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
// Add any thing after that comment 

int trie[MAX][2];
int frq[MAX][2];
int n, k, cnt;

void insert(ll x){

	int cur = 0;

	for (int i = 29; i >= 0; i--){
		
		int w = ((x & (1ll << i)) > 0);
		frq[cur][w]++;
		if (trie[cur][w] == -1){
			trie[cur][w] = ++cnt;
		}
		cur = trie[cur][w];
	}
}

ll find(ll x){
	ll cur = 0, tot = 0;

	for (int i = 29; i >= 0; i--){
		int w = ((x & (1ll << i)) > 0);
		int z = ((k & (1ll << i)) > 0);
		if (!z){
			if (trie[cur][w] == -1)
				return tot;
			cur = trie[cur][w];
		}
		else{
			tot += frq[cur][w];
			if (trie[cur][!w] == -1)
				return tot;
			cur = trie[cur][!w];
		}
	}
	return tot;
}

int main(){
	//fast();
	memset(trie, -1 , sizeof trie);
	memset(frq, 0, sizeof frq);

	scanf("%d%d", &n, &k);
	ll tot = 0, ans = 0;
	int x;
	insert(0);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		tot ^= x;
		ans += find(tot);
		insert(tot);
	}
	ans = (n * 1ll * (n + 1)) / 2 - ans;
	printf("%lld\n", ans);

	return 0;
} 
