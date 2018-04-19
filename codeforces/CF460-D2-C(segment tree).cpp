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
int n, m , w;
int a[5 * 1000 * 100 + 5];
pair<int , int> tree[20 * 1000 * 100 + 5];
int lazy[20 * 1000 * 100 + 5];

void build(int cur, int l, int r){
	if (l == r){
		tree[cur] = { a[l], l };
		return;
	}
	int md = l + r >> 1;
	int left = cur << 1;
	int right = cur << 1 | 1;
	build(left, l, md);
	build(right, md + 1, r);
	if (tree[left].first <= tree[right].first)
		tree[cur] = tree[left];
	else tree[cur] = tree[right];
}
void propgate(int cur, int l, int r){
	if (lazy[cur]){

		tree[cur].first += lazy[cur];
		if (l != r){
			lazy[cur << 1]+= lazy[cur];
			lazy[cur << 1 | 1] += lazy[cur];
		}
		lazy[cur] = 0;
	}
}
void update(int cur, int l, int r, int x, int y ){
	propgate(cur, l, r);
	if (x <= l && y >= r){
		tree[cur].first++;

		lazy[cur << 1]++;
		lazy[cur << 1 | 1]++;
		return;
	}
	if (r <x|| l > y){
		return;
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = cur << 1 | 1;

	update(left, l, md, x, y);
	update(right, md + 1, r, x, y);
	if (tree[left].first <= tree[right].first)
		tree[cur] = tree[left];
	else tree[cur] = tree[right];
}

pair<int , int> query(int cur, int l, int  r, int x, int y){
	propgate(cur, l, r);

	if (x <= l&&y >= r){
		return tree[cur];
	}

	if (r <x|| l > y){
		return{ INT_MAX, -1 };
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = cur << 1 | 1;

	pair<int , int> ll =  query(left, l, md, x, y)  , rr = query(right, md + 1, r, x, y);

	if (ll.first <= rr.first)
		return ll;
	return rr;
}
int main(){
	fast();
	for (int i = 0; i < 20 * 1000 * 100 + 5; i++)
		tree[i] = { INT_MAX, -1 };
	cin >> n >> m>>w;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);

	while (m--){
		int ind = query(1, 1, n, 1, n).second;
		update(1, 1, n, ind, min(n, ind + w - 1));
	}
	cout << query(1, 1, n, 1, n).first << endl;

	return 0;
}
