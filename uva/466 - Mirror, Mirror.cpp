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

int n;
string a[11], b[11];
bool is90D(){
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == b[j][n-i-1])
				cnt++;
		}
	}

	return cnt == n*n;
}

bool is180D(){
	int  cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == b[n-i-1][n-j-1])
				cnt++;
		}
	}
	return cnt == n*n;
}
bool is270D(){
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = n - 1; j >= 0;j--){
			if (a[i][j] == b[n-j-1][i])
				cnt++;
		}
	}
	return cnt == n * n;
}

bool isvert(){
	for (int i = 0; i < n; i++){
		if (a[i] != b[n - i - 1])
			return 0;
	}
	return 1;
}
bool same(){
	for (int i = 0; i < n; i++){
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}
int main()
{
	fast();
	int idx = 1;
	while (cin >> n){
		cout << "Pattern " << idx++;
		for (int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
		}
		if (same()){
			cout << " was preserved.\n";
			continue;
		}
		if (is90D()){
			cout << " was rotated 90 degrees.\n";
			continue;
		}
		if (is180D()){
			cout << " was rotated 180 degrees.\n";
			continue;
		}
		if (is270D()){
			cout << " was rotated 270 degrees.\n";
			continue;
		}
		if (isvert()){
			cout << " was reflected vertically.\n";
			continue;
		}
		for (int i = 0; i < n / 2; i++){
			swap(a[i], a[n - i - 1]);
		}
		if (is90D()){
			cout << " was reflected vertically and rotated 90 degrees.\n";
			continue;
		}
		if (is180D()){
			cout << " was reflected vertically and rotated 180 degrees.\n";
			continue;
		}
		if (is270D()){
			cout << " was reflected vertically and rotated 270 degrees.\n";
			continue;
		}
		
		cout << " was improperly transformed.\n";
	}
	
	return 0;
}
