/*
  trie data structure 
  Just insert all TODO list words in trie
  and find number of prefixes for each query

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
#define OO 1e17
#define EPS 1e-12
#define MLOG 20
#define MAX 25 * 100 * 100+5
const int mod = 1e9+7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);
#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, q;
string s;
vector<vector<int>>trie;
vector<vector<int>>frq;

void add(string &s){
	int cur = 0;

	for (int i = 0; i < s.size(); i++){
		int d = s[i] - 'a';
		frq[cur][d]++;
		if (trie[cur][d] == -1){
			trie[cur][d] = trie.size();
			trie.push_back(vector<int>(26, -1));
			frq.push_back(vector<int>(26, 0));
		}
		cur = trie[cur][d];
	} 
}

int prefix_cnt(string &s){
	int cur = 0;
	int res = 0;
	for (int i = 0; i < s.size(); i++){
		int d = s[i] - 'a';
		if (trie[cur][d] == -1){
			return 0;
		}
		if (i + 1 == s.size())
			return frq[cur][d];
		cur = trie[cur][d];
	}
	return 0;
}
int main(){
	fast();
	cin >> n >> q;
	trie.push_back(vector<int>(26, -1));
	frq.push_back(vector<int>(26, 0));

	for (int i = 0; i < n; i++){
		cin >> s;
		add(s);
	}
	while (q--){
		cin >> s;
		cout << prefix_cnt(s) << endl;
	}
	return 0;
};
