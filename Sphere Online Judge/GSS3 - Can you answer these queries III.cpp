#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e7;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const long long MAX = 50 * 1000 + 1;
int n, q;
struct node{
	long long best, sum, bestL, bestR;
	int mx;
	node(int b, int bl, int br, int s){
		best = b, bestL = bl, bestR = br, sum = s;
	}
	node(){

	}
};

node tree[MAX * 4];
long long a[MAX];

void build(int cur, int l, int r){
	if (l == r){
		tree[cur].bestL = tree[cur].sum = tree[cur].mx=
			tree[cur].bestR =
			tree[cur].best = a[l];
		return;
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	build(left, l, md);
	build(right, md + 1, r);
	tree[cur].best = max(tree[left].best,
		max(tree[right].best,tree[left].bestR + tree[right].bestL));
	tree[cur].bestL = max(tree[left].bestL, tree[left].sum + tree[right].bestL);
	tree[cur].bestR = max(tree[right].bestR, tree[left].bestR + tree[right].sum);
	tree[cur].sum = tree[left].sum + tree[right].sum;
}

void update(int cur, int l, int r, int x, int v){
	if (l == r){
		tree[cur].bestL = tree[cur].sum = tree[cur].mx =
			tree[cur].bestR =
			tree[cur].best = v;
		return;
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	if(md >= x)update(left, l, md ,x ,v);
	else update(right, md + 1, r , x ,v);
	tree[cur].best = max(tree[left].best,
		max(tree[right].best, tree[left].bestR + tree[right].bestL));
	tree[cur].bestL = max(tree[left].bestL, tree[left].sum + tree[right].bestL);
	tree[cur].bestR = max(tree[right].bestR, tree[left].bestR + tree[right].sum);
	tree[cur].sum = tree[left].sum + tree[right].sum;
}

node query(int cur, int l, int r, int x, int y){

	if (x <= l&&y >= r)
		return tree[cur];

	
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	if (y <= md)return query(left, l, md, x, y);
	else if(x>md)return  query(right, md + 1, r, x, y);
	else {
		node three;
		node one = query(left, l, md, x, y);
		node two = query(right, md + 1, r, x, y);

		three.best = max(one.best,
			max(two.best, one.bestR + two.bestL));
		three.bestL = max(one.bestL, one.sum + two.bestL);
		three.bestR = max(two.bestR, one.bestR + two.sum);
		three.sum = one.sum + two.sum;

		return three;
	}
	
}
int main(){
	fast();
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	cin >> q;

	for (int i = 0; i < q; i++){
		int type, x, y;
		cin >> type >> x >> y;
		if (type){
			node w = query(1, 1, n, x, y);
			cout << w.best << endl;
		}
		else{
			update(1, 1, n, x, y);
		}
	}
	return 0;
}
