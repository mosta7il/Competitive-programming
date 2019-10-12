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
int n, t, x;
string s;
vector<vector<int>>trie;
void destroy(){
	trie.clear();
}
int add_node(){
	trie.push_back(vector<int>(2, -1));
	return trie.size() - 1;
}

void insert(int num){
	int cur = 0;
	for (int i = 30; i >= 0; i--){
		bool d = (num & (1 << i));
		if (trie[cur][d] == -1){
			trie[cur][d] = add_node();
		}
		cur = trie[cur][d];
	}
}
pair<int,int> find(int num){
	int cur = 0;
	int mx = 0 ,mxx = 0;
	for (int i = 30; i >= 0; i--){
		bool nd = (num & (1 << i));
		bool xd = (x   & (1 << i));
		if (!xd){
			if (trie[cur][nd ^ 1] != -1){
				mx += (1 << i);
				mxx += (1 << i);
				cur = trie[cur][nd ^ 1];
			}
			else{
				cur = trie[cur][nd];
			}
		}
		else{
			if (trie[cur][nd] != -1){
				mx += (1 << i);
				cur = trie[cur][nd];
			}
			else{
				mxx += (1 << i);
				cur = trie[cur][nd^1];
			}
		}
	}
	return{ mx, mxx };
}
int main(){
	fast();
	cin >> t;
	while (t--){
		cin >> n >> x;
		destroy();
		add_node();
		insert(0);
		int xorsofar = 0, answersofar = 0, ans = 0;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			xorsofar ^= x;
			auto idx = find(xorsofar);
			if (answersofar < idx.first){
				ans = idx.second;
				answersofar = idx.first;
			}
			insert(xorsofar);
		}
		cout << ans << endl;
	}
	return 0;
};
