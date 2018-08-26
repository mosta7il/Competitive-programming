#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>


using namespace std;

typedef complex<double> Point;


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
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX =  1000 + 5;
int n;
int a[MAX];
bool pr[MAX * MAX * 2];
void sieve(){

	pr[0] = pr[1] = 1;

	for (long long i = 2; i*i <= 2 * MAX * MAX; i++){
		if (!pr[i]){
			for (long long j = i * i; j < 2 * MAX * MAX; j += i)
				pr[j] = 1;
		}
	}
}
int mx = 0;

int main() {
	fast();
	sieve();

	cin >> n;
	int ones = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ones += (a[i] == 1);
	}
	if (ones >= 2){
		bool found = 0; int idx = 0;
		for (int i = 0; i < n; i++){
			if (!pr[a[i] + 1]&& a[i] > 1){
				found = 1;
				idx = i;
				break;
			}
		}

		cout << ones + found << endl;
		for (int i = 0; i < n; i++){
			if (a[i] == 1 || (i == idx && found))
				cout << a[i] << " ";
		}
	}
	else{

		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (!pr[a[i] + a[j]]){
					cout << 2 << endl;
					cout << a[i] << " " << a[j] << endl;
					return 0;
				}
			}
		}

		cout << 1 << endl;
		cout << a[0] << endl;
	}
	return 0;
}
