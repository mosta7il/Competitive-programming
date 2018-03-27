#define _CRT_SECURE_NO_WARNINGS
#include<bits\stdc++.h>

using namespace std;

const long long OO = 1e9;
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

int n, k;
string s;
int main(){
	fast();
	cin >> n >> k >> s;
	int j = 0, as = 0, bs = 0, ans = -1;
	for (int i = 0; i < n; i++){

		while (j < n && min(as + (s[j] == 'a'), bs + (s[j] == 'b')) <= k){
			as += (s[j] == 'a');
			bs += (s[j] == 'b');
			ans = max(ans, (j - i + 1));
			j++;
		}
		as -= (s[i] == 'a');
		bs -= (s[i] == 'b');
	}
	cout << ans << endl;

	return 0;
}
