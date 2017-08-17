#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

char G[11][11];
vector<pair<int, int> >v;
bool vis[11][11][64];
bool isv(int i, int j){
	return (i > 0 && j > 0 && i <9 && j <9 );
}
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1, 0 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1, 0 };
bool f;
bool rec(int i, int j, int step){
	if (!isv(i, j) || step>63)
		return 0;

	if (vis[i][j][step])
		return 0;

	if (i - step > 0 && G[i - step][j] == 'S')
		return 0;
	

	if (G[i][j] == 'A'){
		return 1;
	}
	vis[i][j][step] = 1;
	bool res = 0;
	for (int t = 0; t < 9; t++){
		if (isv(i + dx[t] , j + dy[t])){
			if (i + dx[t] - step>0 && G[i + dx[t] - step][j+dy[t]] == 'S')continue;
			if (rec(i + dx[t], j + dy[t], step + 1))return 1;
				
		}
	}
	return 0;
}
int main(){
	fast();

	for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) cin >> G[i][j];
	f = rec(8, 1, 0);
	if (f){
		cout << "WIN" << endl;
	}
	else{
		cout << "LOSE" << endl;
	}
	return 0;
}
//mosta7il_
