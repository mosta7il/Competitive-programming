/*
	

*/

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
#define MLOG 20
#define MAX 1 * 100 * 1000+5

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

struct trie{
	int g[MAX][26];
	int sz = 0;

	void clear(){
		sz = 0;
		memset(g, -1, sizeof g);
	}

	trie(){
		clear();
	}

	void add(string s){
		int cur = 0;

		for (int i = 0; i < s.size(); i++){

			if (g[cur][s[i] - 'a'] == -1){
				g[cur][s[i] - 'a'] = ++sz;
			}
			cur = g[cur][s[i] - 'a'];
		}
	}
};

trie pre, suf;
int n, m , sum[26];

void DFS1(int cur , int dep){
	
	for (int i = 0; i < 26; i++){

		if (suf.g[cur][i] == -1)
			continue;
		if (dep)
			sum[i]++;
		DFS1(suf.g[cur][i], dep + 1);
	}
}

ll DFS(int cur, int dep){

	ll ans = 0;

	if (dep)
		ans += suf.sz;
	for (int i = 0; i < 26; i++){

		if (pre.g[cur][i] == -1)continue;
		if (dep){
			ans -= sum[i];
		}
		ans += DFS(pre.g[cur][i], dep + 1);
	}
	return ans;
}
int main(){
	fast();
	while (cin >> n >> m){
		if (n == 0 && m == 0)break;
	
		memset(sum , 0, sizeof sum);
		string s;
		for (int i = 0; i < n; i++){
			cin >> s;
			pre.add(s);
		}

		for (int i = 0; i < m; i++){
			cin >> s;
			reverse(s.begin(), s.end());
			suf.add(s);
		}
		DFS1(0, 0);

		cout << DFS(0, 0) << endl;

		pre.clear(); suf.clear();
	}

	return 0;
} 
