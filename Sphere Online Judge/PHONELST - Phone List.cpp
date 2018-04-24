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

struct trie{
	trie * nxt[10];
	int end;
	trie(){
		memset(nxt, NULL, sizeof nxt);
		end = 0;
	}

	void insert(int idx ,string s){
		if (idx == s.size()){
			end++;
			return;
		}
		if (nxt[s[idx] - '0'] == NULL){
			nxt[s[idx] - '0'] = new trie();
		}
		end++;
		nxt[s[idx] - '0']->insert(idx + 1, s);
	}

	int find_prefix(int idx, string s){
		if (idx == s.size()){
			return end;
		}
		if (nxt[s[idx] - '0'] == NULL)
			return 0;
		return nxt[s[idx] - '0']->find_prefix(idx + 1, s);
	}
};

string a[100 * 100 + 1];
int main(){
	fast();
	cin >> t;
	while (t--){
		trie *tree = new trie();
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			tree->insert(0, a[i]);
		}
		bool f = 0;
		for (int i = 0; i < n; i++){
			if (tree->find_prefix(0, a[i]) > 1){
				cout << "NO\n";
				f = 1;
				break;
			}
		}
		if (!f){
			cout << "YES\n";
		}
	}


	return 0;
}
