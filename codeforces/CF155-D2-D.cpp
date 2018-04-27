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
int n, m;
int a[1000 * 100 + 5];
bool vis[1000 * 100 + 5];
vector<int> div(int x){
	vector<int>res;
	for (int i = 1; i *i <= x; i++){
		if (x%i == 0){
			if (i > 1)res.push_back(i);
			if (i != x / i)
				res.push_back(x / i);
		}
	}
		return res;
}
int main() {
	fast();
	cin >> n >> m;
	char ty; int v;
	for (int i = 0; i < m; i++){
		cin >> ty >> v;
		if (ty == '+'){
			if (vis[v]){
				cout << "Already on\n";
				continue;
			}
			bool f = 0;
			int idx;
			vector<int>tmp = div(v);
			for (auto e : tmp){
				if (a[e]){
					f = 1;
					idx = a[e];
					break;
				}
			}
			if (!f){
				cout << "Success\n";
				vis[v] = 1;
				for (auto e : tmp){
					a[e] = v;
				}
			}
			else cout << "Conflict with " << idx << '\n';
		}
		else{
			if (!vis[v]){
				cout << "Already off\n";
				continue;
			}
			cout << "Success\n";
			vector<int>tmp = div(v);
			for (auto e : tmp){
				a[e] = 0;
			}
			vis[v] = 0;
		}
	}

	return 0;
}
