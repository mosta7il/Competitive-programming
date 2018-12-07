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
// Add any thing after that comment 

vector< vector< int > > trie;

void destroy(){
	trie.clear();
}
void addNode(){
	trie.push_back(vector<int>(2, -1));
}

void insert(int x){

	int cur = 0;

	for (int i = 31; i >= 0; i--){
		int w = ((x & (1ll << i)) > 0);
		if (trie[cur][w] == -1){
			addNode();
			trie[cur][w] = trie.size() - 1;
		}
		cur = trie[cur][w];
	}
}

int find(int x){
	int cur = 0, tot = 0;

	for (int i = 31; i >= 0; i--){
		int w = ((x & (1ll << i)) > 0);
		w = 1 - w;
		if (trie[cur][w] != -1){
			tot |= (1 << i);
			cur = trie[cur][w];
		}
		else{
			cur = trie[cur][1 - w];
		}
	}
	return tot;
}
int n;
int main(){
	fast();
	int t;
	cin >> t;

	while (t--){
		destroy();
		addNode();
		cin >> n;
		int tot = 0 , mx = 0;
		insert(0);
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			tot ^= x;
			mx = max(mx, find(tot));
			insert(tot);
		}
		cout << mx << endl;
	}
	

	return 0;
} 
