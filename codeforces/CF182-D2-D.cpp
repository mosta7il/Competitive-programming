#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
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
vector<int>p;
string s, t;
int szs, szt;
bool fun(int x , string w){
	int cnt = (w.size() / x);
	string tmp = w.substr(0, cnt) , tt ;
	tt = tmp;
	while (--x){
		tt += tmp;
	}
	return tt == w;

}
map<string, int> mp;

int main(){
	fast();

	cin >> s >> t;
    szs = s.size(), szt = t.size();

	for (int i = 1; i*i <= szs; i++){
		if (szs%i == 0){
			p.push_back(i);
			if (szs / i != i)
				p.push_back(szs / i);
		}
	}

	for (int i = 0; i < p.size(); i++){
		if (fun(p[i], s)){
			mp[s.substr(0, s.size() / p[i])]++;
		}
	}
	p.clear();
	for (int i = 1; i*i <= szt; i++){
		if (szt%i == 0){
			p.push_back(i);
			if (szt / i != i)
				p.push_back(szt / i);
		}
	}
	int res = 0;
	for (int i = 0; i < p.size(); i++){
		if (fun(p[i], t)){
			if (mp[t.substr(0, t.size() / p[i])] > 0)
				res++;
		}
	}
	cout << res << endl;
	return 0;
}
