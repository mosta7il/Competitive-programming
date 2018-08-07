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
struct node{
	int val;
	int l, r;
	bool q;
	int idx;
	bool operator < (const node & e)const{
		if (val > e.val)
			return 1;
		else if (val == e.val)
			return q;
		return 0;
	}
};
int n, q;
vector< node > v;
long long tree[4 * MAX];

void update(int cur, int l, int r, int x){
	if (l == r){
		tree[cur]++;
		return;
	}
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	if (md >= x)
		update(left, l, md, x);
	else update(right, md + 1, r, x);
	tree[cur] = tree[left] + tree[right];
}

long long query(int cur, int l, int r, int x, int y){
	if (x <= l && y >= r)
		return tree[cur];

	if (r < x || l > y)
		return 0;
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	
	return query(left, l, md, x, y) +
		query(right, md + 1, r, x, y);
}
long long ans[MAX*10];
int main(){
	//fast();
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		node tmp;
		int x; 	scanf("%d", &x);
		tmp.val = x; tmp.l = i; tmp.r = i;
		tmp.q = 0;
		v.push_back(tmp);
	}
	
	scanf("%d", &q);

	for (int i = 0; i < q; i++){
		node tmp;
		int x, y, k;
		scanf("%d %d %d", &x , &y , &k);
		tmp.val = k;
		tmp.l = x; tmp.r = y;
		tmp.q = 1;
		tmp.idx = i;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++){
		if (v[i].q){
			ans[v[i].idx] = query(1, 1, n, v[i].l, v[i].r);
		}
		else{
			update(1, 1, n, v[i].l);
		}
	}

	for (int i = 0; i < q; i++)
		printf("%lld\n" ,ans[i]);
	return 0;
}
