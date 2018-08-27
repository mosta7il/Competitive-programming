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
const long long MAX = 10 * 100 * 1000 + 5;

string s;
int main() {
	fast();

	cin >> s;
	if (s.find('.') != -1){
		while (s.back() == '0')s.pop_back();
		int i = 0;
		while (s[i] == '0')
			i++;
		s.erase(s.begin(), s.begin() + i);

	}
	else{
		int i = 0;
		while (s[i] == '0')
			i++;
		s.erase(s.begin(), s.begin() + i);
		s += ".";
	}
	if (s == "."){
		cout << 0 << endl;
		return 0;
	}
	if (s[0] == '.'){
		int cur = 1;
		while (s[cur] == '0')
			cur++;
		s.insert(s.begin() + cur+1, '.');
		s.erase(s.begin(), s.begin() + cur);

		if (s.back() == '.')
			s.pop_back();
		cout << s << "E"<<-cur<<"\n";

		return 0;
	}
	
	int idx = s.find('.'),
		cnt = 0;
	while (idx > 1){
		swap(s[idx], s[idx - 1]);
		idx--; cnt++;
	}
	while (s.back() == '0')
		s.pop_back();
	if (s.back() == '.')
		s.pop_back();
	cout << s;
	if (cnt > 0)
		cout << "E" << cnt << endl;
	return 0;
}
