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
#include<map>
#include<fstream>


using namespace std;

bool p[100004];
void seive(){
	p[1] = 1;
	for (int i = 2; i * i <= 100003; i++){
		if (!p[i]){
			for (int j = i + i; j < 100004; j += i){
				p[j] = 1;
			}
		}
	}
}
int a[501][501];
int main(){
	ifstream fin("A-large-practice.in");
	ofstream fout("A.out");
	seive();
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++){
			cin >>a[i][j];
		}
	}
	int cnt = 0, mn = (1e9); 
	for (int r = 0; r < n; r++){
		cnt = 0; 
		for (int c = 0; c < m; c++){
			if (p[a[r][c]]){
				for (int w = a[r][c] + 1; w < 100004; w++){
					if (!p[w]){
						cnt += w - a[r][c];
						w = 100004;
					}
				}
			}
		}
		mn = min(mn, cnt);
	}

	for (int c = 0; c < m; c++){
		cnt = 0;
		for (int r = 0; r < n; r++){
			if (p[a[r][c]]){
				for (int w = a[r][c] + 1; w < 100004; w++){
					if (!p[w]){
						cnt += w - a[r][c];
						w = 100004;
					}
				}
			}
		}
		mn = min(mn, cnt);
	}

		cout << mn << endl;
	
	return 0;
}
// mosta7il_
