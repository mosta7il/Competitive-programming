#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>

using namespace std;
char q[11][11];
int main(){

	int n, m, res = 0;
	cin >> n >> m;

	for (int i = 0; i < n;i++)
	for (int j = 0; j < m; j++)
		cin >> q[i][j];

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++){
		if (q[i][j] == 'P'){
			if (j + 1 < m && q[i][j + 1] == 'W'){ //R
				res++;
				q[i][j] = '.', q[i][j + 1] = '.';
			}
			if (j - 1 >= 0&& q[i][j - 1] == 'W'){ //L
				res++;
				q[i][j] = '.', q[i][j - 1] = '.';
			}
			if (i + 1 < n && q[i+1][j] == 'W'){ //D
				res++;
				q[i][j] = '.', q[i+1][j] = '.';
			}
			if (i-1 >=0 && q[i-1][j] == 'W'){ //T
				res++;
				q[i][j] = '.', q[i-1][j] = '.';
			}
		}
	}

	cout << res << endl;

	return 0;
}
