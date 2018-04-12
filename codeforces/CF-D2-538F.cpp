#define _CRT_SECURE_NO_WARNINGS
// Do not work at uva or spoj..
#include<bits\stdc++.h> 
using namespace std;

const long long OO = 1000;
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
const int MAX = 2e5 + 1;

int n, k;
int a[MAX];
vector<int> tree[MAX * 4];

void build(int cur, int l, int r){
	if (l == r){
		tree[cur].push_back(a[l]);
		return;
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left + 1;
	build(left, l, md);
	build(right, md + 1, r);
	int i = 0, j = 0;
	for (; i < tree[left].size()&&tree[right].size()>j;){
		if (tree[left][i] <= tree[right][j]){
			tree[cur].push_back(tree[left][i]);
			i++;
		}
		else {
			tree[cur].push_back(tree[right][j]);
			j++;
		}
	}
	while (i < tree[left].size()){
		tree[cur].push_back(tree[left][i]);
		i++;
	}
	while (j < tree[right].size()){
		tree[cur].push_back(tree[right][j]);
		j++;
	}
}

int query(int cur, int l, int r, int x, int y, int v){
	if (x <= l&&y >= r){
		return (lower_bound(tree[cur].begin(), tree[cur].end(), v) - tree[cur].begin());
	}

	if (r<x || l>y)
		return 0;
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left + 1;
	return query(left, l, md, x, y, v) + query(right, md + 1, r, x, y, v);
}
int main(){
	fast();
	cin >> n;
	memset(a, 2e9 ,sizeof a);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	for (int k = 1; k < n; k++){
		int cost = 0;
		for (int par = 1; par < n; par++){
			int l = k*(par - 1) + 2, r = k *par + 1;
			r = min(r, n);
			if (l > n)
				break;
			cost += query(1, 1, n, l, r, a[par]);
		}
		cout << cost << " ";
	}
	return 0;
}
