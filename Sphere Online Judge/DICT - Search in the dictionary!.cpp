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
struct trie{
	trie *nxt[26];
	vector<string>cnt;
	bool end;

	trie(){
		memset(nxt, 0, sizeof nxt);
		cnt.clear();
		end  = 0;
	}

	void insert(int idx, string s){
		if (idx == s.size()){
			end = 1;
			return;
		}

		if (nxt[s[idx] - 'a'] == 0){
			nxt[s[idx] - 'a'] = new trie();
		}
		cnt.push_back(s);
		nxt[s[idx] - 'a']->insert(idx + 1, s);
	}

	vector<string> find_prefix(int idx, string s){
		if (idx == s.size()){
			return cnt;
		}

		if (nxt[s[idx] - 'a'] == 0){
			return vector<string>(0);
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

	for (auto i : s){
		tree->insert(0, i);
	}
	cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> ss;
		cout << "Case " << "#" << i << ":\n";
		vector<string> res = tree->find_prefix(0, ss);
		if (res.size() == 0)
			cout << "No match.\n";
		else {
			sort(res.begin(), res.end());
			for (auto e : res)
				cout << e << "\n";
		}
	}
	return 0;
}
