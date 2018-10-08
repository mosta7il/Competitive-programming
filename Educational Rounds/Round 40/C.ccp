#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
const long long  OO = 1e9;
const long long mod = 1e9 + 7;

int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 2 * 100 * 1000 + 5;
int n;
map<int , int>s;
int a[MAX];
int col, mx, row;

bool isv(int i, int j){
	return (i >= 1 && j >= 1 && i <= row&&j <= col);
}
int main() {
	fast(); 
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
		if (abs(a[i] - a[i - 1]) == 0){
			return cout << "NO\n", 0;
		}
		if (i){
			s[abs(a[i] - a[i - 1])]++;
		}
	}
	if (n == 1){
		cout << "YES\n";
		return cout << "1 " << a[0] << endl, 0;
	}
	if (s.size() > 2){
		return cout << "NO\n", 0;
	}
	else if (s.size() == 1 && (*s.begin()).first == 1){
		col = 1;
		row = (mx / col) + (mx%col > 0);
	}
	else if (s.size() == 1 && (*s.begin()).first > 1){
		col = (*s.begin()).first;
		row = (mx / col) + (mx%col > 0);
	}
	else{
		auto it = s.begin(); it++;
		col = (*it).first;
		row = (mx / col) + (mx%col > 0);
	}
	int cur = a[0];
	int curx = (a[0] / col) + (a[0] % col > 0), cury = ((a[0] - 1) % col + col) % col + 1;
	for (int  i = 1; i < n; i++){
		bool f = 0;
		for (int d = 0; d < 4; d++){
			int ii = curx + dx[d], jj = cury + dy[d];
			if (isv(ii, jj) ){
				if ((((col * (ii - 1)) + jj) == a[i])){
					curx = ii, cury = jj;
					f = 1;
					break;
				}
			}
		}
		if (!f){
			return cout << "NO\n", 0;
		}
	}

	cout << "YES\n";
	cout << row << " " << col << endl;
	return 0;
}
