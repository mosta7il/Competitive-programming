#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e10;
const long long mod = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ld long double
void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const long long MAX = 100 * 1000 + 5;
string s;
int frq[26];

int main() {
	fast();
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		frq[s[i] - 'a']++;
	int idx = 0;
	string ans = "", t = "";
	for (int i = 0; i < s.size(); i++){
		while (idx<26&&frq[idx] == 0)
			idx++;
		if (idx == 26)break;
		while (t.size() && t.back() <= char(idx + 'a')){
			ans += t.back();
			t.pop_back();
		}
		if (s[i] <= char(idx + 'a')){
			ans += s[i];
		}
		else{
			t += s[i];
		}
		frq[s[i] - 'a']--;
	}
	while (t.size() ){
		ans += t.back();
		t.pop_back();
	}
	cout << ans << endl;
	return 0;
}
