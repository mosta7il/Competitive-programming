#define _CRT_SECURE_NO_WARNINGS
#include<bits\stdc++.h>
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
map < pair< pair< int, int >, pair<string, string> >  , vector<int>> mp;
int main(){
	fast();
	
	while (cin >> n >> m){
		cin.ignore();
		mp.clear();
		vector<string>g[100 * 100 + 1];
		
		for (int i = 0; i < n; i++){
			string w = "" , tmp = "";
			getline(cin, w);
			for (int j = 0; j < w.size(); j++){
				if (w[j] == ','){
					g[i].push_back(tmp);
					tmp = "";
				}
				else{
					tmp += w[j];
				}
			}
			g[i].push_back(tmp);
		}

		for (int i = 0; i < m; i++){
			for (int j = i + 1; j < m; j++){
				for (int k = 0; k < n; k++){
					mp[{{ i+1, j+1 }, { g[k][i], g[k][j] }}].push_back(k+1);
				}
			}
		}
		bool f = 0;
		for (auto e : mp){
			if (e.second.size() >= 2){
				f = 1;
				cout << "NO\n";
				cout << e.second[0] << " " << e.second[1] << '\n';
				cout << e.first.first.first << " " << e.first.first.second << '\n';
				break;
			}
		}
		if (!f){
			cout << "YES\n";
		}
	}
	return 0;
}
