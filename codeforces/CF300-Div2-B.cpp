#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<queue>

using namespace std;

vector<int> *G , temp;
vector<vector<int> > vv;
bool vis[50];
int no = 0;
void dfs(int v){
	if (vis[v])
		return;
	vis[v] = 1;
	no++;
	temp.push_back(v);
	for (int i = 0; i < G[v].size(); i++){
		if (!vis[G[v][i]])
			dfs(G[v][i]);
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	if (m == 0){
		for (int i = 1; i < n; i += 3){
				cout << i << " " << i + 1 << " " << i + 2 << endl;
			
		}
		return 0;
	}
	
	G = new vector<int>[n+1];
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	if (n == 3){
		cout << 1 << " " << 2 << " " << 3 << endl;
		return 0;
	}
	vector<int> ones;
	vector<vector<int> > tws;
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			temp.erase(temp.begin(), temp.end());
			no = 0;
			dfs(i);
			if (no > 3){
				cout << -1 << endl;
				return 0;
			}
			else if (no == 3){
				vv.push_back(temp);
			}
			else {
				if (no == 1){
					ones.push_back(i);
				}
				else{
					tws.push_back(temp);
				}
			}
		}
	}
	int ss1 = ones.size(), ss2 = tws.size();
	if (ss1 - ss2 > 0){
		if ((ss1 -ss2) % 3 == 0){
			int e = ones.size() - tws.size();
			for (int i = 0; i < e; i+=3){
				cout << ones[0] << " " << ones[1] << " " << ones[2] << endl;
				ones.erase(ones.begin(), ones.begin() + 3);
			}
		}
		else{
			cout << -1 << endl;
			return 0;
		}
	}
	else if(ss1 -ss2<0){
		cout << -1 << endl;
		return 0;
	}
	ss1 = ones.size(), ss2 = tws.size();
	if ((ss1 - ss2) == 0){
		for (int i = 0; i < tws.size(); i++){
			cout << tws[i][0] << " " << tws[i][1] << " " << ones[i] << endl;
		}
	}
	for (int i = 0; i < vv.size(); i++){
		for (int j = 0; j < 3; j++){
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
