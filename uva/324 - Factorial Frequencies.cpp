#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e9;
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
const long long MAX = 200 * 1000 + 1;
int n;

int number[1001];
int tmp[1001][3];

void mul(int x){

	int cnt = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 1001; j++)
			tmp[j][i] = 0;
	}

	while (x){
		int dig = x % 10;
		x /= 10;
		int car = 0;
		for (int idx = 0; idx < 900; idx++){
			tmp[idx + cnt][cnt] = (dig * number[idx] + car) % 10;
			car = (dig * number[idx] + car) / 10;
		}
		cnt++;
	}
	int carry = 0;
	for (int i = 0; i < 1001; i++){
		number[i] = (tmp[i][0] + tmp[i][1] + tmp[i][2] + carry) % 10;
		carry = (tmp[i][0] + tmp[i][1] + tmp[i][2] + carry) / 10;
	}

}
int ans[10];
int main(){
	//fast();
	
	while (cin >> n&&n){
		cout << n << "! --\n";
		for (int i = 0; i < 10; i++)
			ans[i] = 0;

		for (int i = 0; i < 1001; i++)
			number[i] = 0;
		number[0] = 1;

		for (int i = 1; i <= n; i++){
			mul(i);
		}
		bool f = 0;
		for (int i = 1000; i >= 0; i--){
			if (!f &&number[i] != 0){
				f = 1;
			}
			if (f){
				ans[number[i]]++;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (i)
				printf("    ");
			else
				printf("   ");
			printf("(%d)%5d", i, ans[i]);
		}
		cout << endl;
		for (int i = 5; i < 10; i++) {
			if (i != 5)
				printf("    ");
			else
				printf("   ");
			printf("(%d)%5d", i, ans[i]);
		}
		cout << endl;
	}

	return 0;
}
