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
const long long MAX = 2 * 1000 + 1;

int t;
int x, y;
int row[8];
int cnt;
bool can(int r, int c){

	for (int idx = 0; idx < c; idx++){
		if (row[idx] == r || abs(r - row[idx]) == abs(c - idx))
			return 0;
	}
	return 1;
}
void backtrack(int c){
	if (c == 8){
		if (row[y] == x){
			cout << setw(2)<< ++cnt << "      ";
			for (int idx = 0; idx < 8; idx++){
				if (idx)cout << " ";
				cout << row[idx]+1;
			}
			cout << endl;
		}
		return;
	}

	for (int r = 0; r < 8; r++){
		if (can(r, c)){
			row[c] = r;
			backtrack(c + 1);
		}
	}

}
int main(){
	fast();
	cin >> t;
	while (t--){
		cin >> x >> y;
		x--, y--;
		cnt = 0;
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";
		backtrack(0);
		if (t)cout << endl;
	}
	return 0;
}
