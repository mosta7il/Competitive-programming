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
const long long MAX =  3 * 100 * 1000 + 5;

string s;

int main() {
	fast();
	
	cin >> s;

	for (int i = 0; i < s.size()-1; i++){
		if (s[i] == s[i + 1]){
			for (char x = 'a'; x <= 'z'; x++){
				if (x != s[i] && x != s[i + 2]){
					s[i + 1] = x;
					break;
				}
			}
		}
	}
	cout << s << endl;
	return 0;
}
