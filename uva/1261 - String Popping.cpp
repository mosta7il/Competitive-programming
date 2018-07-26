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
int t;
string s;
map<string, int> mem;

int rec(string w){

	if (mem.count(w))
		return mem[w];
	int ret = 1e9;
	int i = 0, j = 0; bool f = 0;
	while (i < w.size()){
		j = i;
		while (j < w.size() && w[j] == w[i])j++;

		if (j - i > 1){
			f = 1;
			ret = min(ret, rec(w.substr(0, i) + w.substr(j)));
		}
		i = j;
	}

	if (!f)
		return mem[w] = w.size();
	return mem[w] = ret;
}
int main(){
	fast();
	cin >> t;
	while (t--){
		cin >> s;
		//mem.clear();
		cout << (rec(s)?0:1) << endl;
	}
	return 0;
}
