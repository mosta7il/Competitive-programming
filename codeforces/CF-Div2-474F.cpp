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
int n, m;

pair<int , int> tree[MAX * 16];
int a[MAX];
int gcd(int a, int b){

	if (!b){
		return a;
	}
	return gcd(b, a%b);
}
void build(int cur, int l, int r){
	if (l == r){
		tree[cur] = { a[l], 1 };
		return;
	}
	int mid = (l + r) / 2;
	int left = cur * 2;
	int right = left + 1;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur].first = gcd(tree[left].first, tree[right].first);
	tree[cur].second += (tree[cur].first == tree[left].first) ? tree[left].second:0;
	tree[cur].second += (tree[cur].first == tree[right].first) ? tree[right].second : 0;
}

int  query1(int cur, int l, int r, int x, int y){
	if (r<x || l>y)
		return 0;
	if (x <= l&& y >= r){
		return tree[cur].first;
	}
	int mid = (l + r) / 2;
	int left = cur * 2;
	int right = left + 1;
	return gcd(query1(left, l, mid, x, y),
		query1(right, mid + 1, r, x, y));
}

int query2(int cur, int l, int r, int x, int y , int val){
	if (r<x || l>y)
		return 0;
	if (x <= l&& y >= r){
		return (tree[cur].first == val)?tree[cur].second:0;
	}
	int mid = (l + r) / 2;
	int left = cur * 2;
	int right = left + 1;
	return query2(left, l, mid, x, y , val)+
		query2(right, mid + 1, r, x, y , val);
}
int main(){
	fast();
	cin >> n; 

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++){
		int l, r; cin >> l >> r;
		cout <<(r-l+1)- query2(1, 1, n, l, r , query1(1 , 1 , n ,l  , r)) << endl;
	}
	
	return 0;
}
