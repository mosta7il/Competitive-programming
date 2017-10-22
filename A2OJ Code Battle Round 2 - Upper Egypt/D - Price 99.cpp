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

const int MAX = 11;
int nn[10];
struct trie{

	trie* child[MAX];
	bool isleaf;
	int sz;
	trie(){
		for (int i = 0; i < 10; i++){
			child[i] = NULL;
		}
		isleaf = sz = 0;
	}

	void add(trie*& tmp, int s, int ind){
		if (tmp == NULL)
			tmp = new trie();

		tmp->sz++;
		if (ind == MAX){
			tmp->isleaf = true;
			return;
		}

		add(tmp->child[s % 10], s / 10, ind + 1);
	}

	pair<long long, long long> isexist(trie*& tmp, int s, int in){
		if (in == MAX){
			return{ in - 1, tmp->sz };
		}
		if (tmp->child[9 - s % 10] == NULL)
			return{ in - 1, tmp->sz };
		return isexist(tmp->child[9 - s % 10], s / 10, in + 1);
	}

};
string a[150 * 1000 + 1];

int main(){
	trie* root = new trie();
	int n;
	cin >> n;
	long long mx = 0, ans = 0;
	for (int i = 0; i< n; i++){
		int u;
		cin >> u;
		pair < long long, long long>p = root->isexist(root, u, 1);
		if (p.first > mx)
			mx = p.first, ans = p.second;
		else if (p.first == mx)
			ans += p.second;
		root->add(root, u, 1);
	}
	cout << mx << " " << ans << endl;
	return 0;
}
//mosta7il_
