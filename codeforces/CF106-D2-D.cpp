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
int n, m, k;
int N[1001][1001], W[1001][1001];
char g[1001][1001];
vector< pair< int, int > > v;
vector<char>ans;
int main(){
	fast();
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		int c = 0;
		for (int j = 0; j < m; j++){
			cin >> g[i][j];
			if (g[i][j] == '#')
				c = 0;
			W[i][j] = c;
			c += (g[i][j] != '#');
			if ( g[i][j] !='.' && g[i][j] !='#'){
				v.push_back({ i, j });
			}
		}
	}	


	for (int j = 0; j < m; j++){
		int c = 0;
		for (int i = 0; i < n; i++){
			if (g[i][j] == '#')
				c = 0;
			N[i][j] = c;
			c += (g[i][j] != '#');
			
		}
	}

	cin >> k;
	vector< pair< char, int> > move(k);
	for (int i = 0; i <k; i++)
		cin >> move[i].first >> move[i].second;


	for (int i = 0; i < v.size(); i++){
		auto cur = v[i]; 
		bool f = 0;
		for (int j = 0; j < move.size(); j++){
			if (move[j].first == 'N'){
				if (N[cur.first][cur.second] < move[j].second){
					f = 1;
					break;
				}
				cur.first -= move[j].second;
			}
			else if (move[j].first == 'S'){
				if (N[cur.first + move[j].second][cur.second] < move[j].second){
					f = 1;
					break;
				}
				cur.first += move[j].second;
			}
			else if (move[j].first == 'E'){
				if (W[cur.first][cur.second + move[j].second] < move[j].second){
					f = 1;
					break;
				}
				cur.second += move[j].second;
			}
			else{
				if (W[cur.first][cur.second] < move[j].second){
					f = 1;
					break;
				}
				cur.second -= move[j].second;
			}
		}
		if (!f){
			ans.push_back(g[v[i].first][v[i].second]);

		}
	}
	if (!ans.size()){
		cout << "no solution\n";
	}
	else {
		sort(ans.begin(), ans.end());
		for (auto i : ans)
			cout << i;
	}
	return 0;
}
