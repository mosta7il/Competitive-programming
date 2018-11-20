/*
    ** pattern 447  - if the first '4' in odd position - will flip
    between pattern 477 and 447 every step.

    ** so we process all substrings "47" until we got "477" , Or we reach the end of string. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-9);
const ll   OO = 1e18;
const ll   mod = 1e9 + 7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MLOG = 30;
const int MAX = 10 * 100 * 1000 + 5;
int n, k;

string s;

int main(){
	fast();

	cin >> n >> k;
	cin >> s;
	// 447 odd
	for (int i = 1; i < n && k; i++){
		if (s[i] == '7' && s[i - 1] == '4'){
			if (i - 2 >= 0 && s[i - 2] == '4'){
				if ((i - 2) & 1){ s[i] = '4'; k--; }
				else{ k %= 2; if (k){ s[i - 1] = '7'; k--; } }
			}
			else{
				if ((i - 1) & 1){ s[i - 1] = '7'; k--; }
				else{ s[i] = '4'; k--; }

			}
		}
	}
	cout << s << endl;
	
	return 0;
}
