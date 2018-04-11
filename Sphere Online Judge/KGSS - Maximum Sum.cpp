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
const int MAX = 1e5 + 1;

int a[MAX], tree[MAX * 4][2];
int n, q, x, y;

void build(int cur, int l, int r){
	if (l == r){
		tree[cur][0] = a[l];
		return;
	}
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left + 1;
	build(left, l, md);
	build(right, md + 1, r);
	if (tree[left][0] >= tree[right][0]){
		tree[cur][0] = tree[left][0];
		tree[cur][1] = max(tree[left][1], tree[right][0]);
	}else{
		tree[cur][0] = tree[right][0];
		tree[cur][1] = max(tree[left][0], tree[right][1]);
	}
}

void update(int cur, int l, int r){
	if (l == r){
		tree[cur][0] = y;
		return;
	}
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left + 1;
	if (x <= md){
		update(left, l, md);
	}
	else{
		update(right, md + 1, r);
	}
	if (tree[left][0] >= tree[right][0]){
		tree[cur][0] = tree[left][0];
		tree[cur][1] = max(tree[left][1], tree[right][0]);
	}
	else{
		tree[cur][0] = tree[right][0];
		tree[cur][1] = max(tree[left][0], tree[right][1]);
	}
}

pair<int ,int> query(int cur, int l, int r){
	if (x <= l&&y >= r){
		return{ tree[cur][0], tree[cur][1] };
	}
	if (r<x || l>y){
		return{ 0, 0 };
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left + 1;

	pair<int, int>lftRet = query(left, l, md);
	pair<int, int>rgtRet = query(right, md + 1, r);
	if (lftRet.first >= rgtRet.first){
		return{ lftRet.first, max(rgtRet.first, lftRet.second) };
	}
	else{
		return { rgtRet.first, max(rgtRet.second, lftRet.first) };
	}
}
int main(){
	fast();
	memset(tree, -1, sizeof tree);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	cin >> q;
	for (int i = 0; i < q; i++){
		char c;
		cin >> c >> x>>y;
		if (c == 'U'){
			update(1, 1, n);
		}
		else{
			pair<int, int> res = query(1, 1, n);
			cout << res.first + res.second << endl;
		}
	}
	return 0;
}
