#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
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
int n;
string a[1000 * 100 + 1];
struct trie{

	trie * tree[26];
	bool end;

	trie(){
		memset(tree, 0, sizeof tree);
		end = 0;
	}

	void insert(string s, int idx){
		if (idx == s.size()){
			end = 1;
			return;
		}

		if (tree[s[idx] - 'a'] == 0){
			tree[s[idx] - 'a'] = new trie();
		}
		tree[s[idx] - 'a']->insert(s, idx + 1);
	}
	int get(string s, int idx,bool prev){
		if (idx == s.size()){
			return 0;
		}
		bool f = tree[s[idx] - 'a']->end;
		if (idx == 0 ||prev){
			return 1 + tree[s[idx]-'a']->get(s, idx + 1, f);
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++){
			cnt += (tree[i] != 0);
		}
		if (cnt == 1){
			return tree[s[idx] - 'a']->get(s, idx + 1 , f);
		}
		return 1 + tree[s[idx] - 'a']->get(s, idx + 1, f);
	}
};
int main() {
	fast();
	while (cin >> n){
		trie * oo = new trie();
		int sum = 0, cnt = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			oo->insert(a[i], 0);
			sum += a[i].size();
		}
		for (int i = 0; i < n; i++){
			cnt +=oo->get(a[i], 0,1);
		}
		cout << fixed << setprecision(2) << cnt *1.0 / n << endl;
	}

	return 0;
}
