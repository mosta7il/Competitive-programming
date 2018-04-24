#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e6;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, t;
set<string>s;
string a[1000 * 25 + 1];
struct trie{
	trie *nxt[26];
	vector<int>cnt;
	bool end;

	trie(){
		memset(nxt, 0, sizeof nxt);
		cnt.clear();
		end  = 0;
	}

	void insert(int idx, string s , int i){
		if (idx == s.size()){
			end = 1;
			return;
		}

		if (nxt[s[idx] - 'a'] == 0){
			nxt[s[idx] - 'a'] = new trie();
		}
		cnt.push_back(i);
		nxt[s[idx] - 'a']->insert(idx + 1, s , i);
	}

	vector<int> find_prefix(int idx, string s){
		if (idx == s.size()){
			return cnt;
		}

		if (nxt[s[idx] - 'a'] == 0){
			return vector<int>(0);
		}
		return nxt[s[idx] - 'a']->find_prefix(idx + 1, s);
	}
};
int main(){
	fast();
	cin >> n;
	trie * tree = new trie();
	string ss;
	for (int i = 0; i < n; i++){
		cin >> ss;
		s.insert(ss);
	}
	int id = 0;
	for (auto i : s){
		a[id] = i;
		tree->insert(0, a[id] , id);
		id++;
	}
	cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> ss;
		cout << "Case " << "#" << i << ":\n";
		vector<int> res = tree->find_prefix(0, ss);
		if (res.size() == 0)
			cout << "No match.\n";
		else {
			for (auto e : res)
				cout << a[e] << "\n";
		}
	}
	return 0;
}
