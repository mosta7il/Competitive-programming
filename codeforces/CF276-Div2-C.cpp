#include<bits\stdc++.h>
const int oo = 1e9;
const int maxx = 2e5 + 2;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
long long a[maxx]; int n, q;
pair<int, int>qu[maxx];
pair<long long, int>w[maxx];
long long z[maxx];
bool cmp(pair<int, int> i, pair<int, int> j){
	if (i.first > j.first)return 1;
	return 0;
}
bool com(int i, int j){
	if (i > j)return 1;
	return 0;
}
int main(){
	fast();
	cin >> n >> q;
	for (int i = 0; i < n; cin >> a[i++]);
	for (int i = 0; i < q; i++){
		cin >> qu[i].first >> qu[i].second;
		w[qu[i].first].first += 1;
		w[qu[i].second+1].first -= 1;
	}
	for (int i = 1; i <= n; i++){
		w[i].first += w[i - 1].first;
		w[i].second = i;
	}
	sort(w + 1, w + 1 + n, cmp);
	sort(a, a + n , com);
	for (int i = 1; i <= n; i++){
		z[w[i].second] = a[i - 1];
	}
	for (int i = 1; i <= n; i++)
		z[i] += z[i - 1];
	long long cnt = 0;
	for (int i = 0; i < q; i++){
		cnt += (z[qu[i].second] - z[qu[i].first - 1]);
	}
	cout << cnt << endl;
	return 0;
}
//mosta7il_
