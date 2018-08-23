#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> Point;

const long long OO = 1e9;
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
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 2 * 100 * 1000 + 5;

int n;
int tree[4 * MAX];
vector< pair< pair< int, int>, int> >v;
vector<int>ans;
vector< pair<int, int> >s;

void update(int cur, int l, int r, int idx){
	if (l == r){
		tree[cur]++;
		return;
	}
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	if(md >= idx)update(left, l, md, idx);
	else update(right, md + 1, r, idx);
	tree[cur] = tree[left] + tree[right];
}

int query(int cur, int l , int r, int x, int y){
	if (x <= l &&y >= r)
		return tree[cur];
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	if (y <= md)
		return query(left, l, md, x, y);
	else if (x > md)
		return query(right, md + 1, r, x, y);
	else
		return query(left, l, md, x, y)
		+ query(right, md + 1, r, x, y);
}
int main() {
	fast();
	cin >> n;
	v.resize(n); ans.resize(n, 0); s.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].first.first >> v[i].first.second;
		s[i] = { v[i].first.second, i };
		v[i].second = i;
	}
	sort(s.begin(), s.end());
	
	for (int i = 0; i < n; i++){
		v[s[i].second].first.second = i + 1;
	}
	sort(v.begin(), v.end());

	for (int i = n -1; i >= 0 ; i--){
		ans[v[i].second] = query(1, 1, n, 1, v[i].first.second);
		update(1, 1, n, v[i].first.second);
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";

	return 0;
}
