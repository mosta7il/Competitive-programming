#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1 , 1 , 1 , -1 , -1};
int dy[] = { 1, -1, 0, 0 ,1 ,-1 , 1 , -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
string s;
int n;
int frq[26];
int main() {
	fast();
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		frq[s[i] - 'a']++;
	n = s.size();
	string res = "";
	if (n % 2){
		char b = '*';
		int odd = 0;
		for (int i = 0; i < 26; i++){
			odd += (frq[i] % 2);
		}
		for (int i = 0; i < 26; i++){
			int idx = -1;
			for (int j = 0; j < frq[i] / 2; j++)
				res += (i + 'a');

			if (frq[i] % 2){
				if (odd == 1){
					b = (i + 'a');
				}
				else{
					for (int j = i + 1; j < 26; j++){
						if (frq[j] % 2)
							idx = j;
					}
					res += (i + 'a');
					frq[idx]--;
					odd--;
				}
				odd--;
			}

		}
		
		cout << res << b;
		reverse(res.begin(), res.end());
		cout << res << endl;
	}
	else{
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < frq[i] / 2; j++)
				res += (i + 'a');
			if (frq[i] % 2){
				for (int j = 25; j>i; j--){
					if (frq[j] % 2){
						res += (i + 'a');
						frq[j]--;
						break;
					}
				}
			}
		}
		cout << res;
		reverse(res.begin(), res.end());
		cout << res << endl;
	}
	return 0;
}
