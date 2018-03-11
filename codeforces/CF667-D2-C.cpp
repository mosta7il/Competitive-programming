#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("E:\\Programming\\Problem Solving\\inout files\\input.txt", "r", stdin);
	freopen("E:\\Programming\\Problem Solving\\inout files\\output.txt", "w", stdout);
#endif
}
string s;
set<string>st;
int ok[10005][4];
bool rec(int idx, int last){
	if (idx > s.size())
		return 0;
	if (idx == s.size())
		return 1;
	int &ret = ok[idx][last];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	if (last == 0){
		if (rec(idx + 2, 2)){
			st.insert(s.substr(idx, 2));
			ret = 1;
		}
		if (rec(idx + 3, 3)){
			st.insert(s.substr(idx, 3));
			ret = 1;
		}
	}
	else if (last == 2){
		if (s.substr(idx - last, 2) != s.substr(idx, 2)){
			if (rec(idx + 2, 2)){
				st.insert(s.substr(idx, 2));
				ret = 1;
			}
		}
		if (rec(idx + 3, 3)){
			st.insert(s.substr(idx, 3));
			ret = 1;
		}
	}
	else{
		if (s.substr(idx - last, 3) != s.substr(idx, 3)){
			if (rec(idx + 3, 3)){
				st.insert(s.substr(idx, 3));
				ret = 1;
			}
		}
		if (rec(idx + 2, 2)){
			st.insert(s.substr(idx, 2));
			ret = 1;
		}
	}
	return ret;
}
int main(){
	fast();
	memset(ok, -1, sizeof ok);
	cin >> s;
	for (int i = 5; i < s.size(); i++){
		rec(i, 0);
	}
	cout << st.size() << endl;
	for (auto e : st){
		cout << e << endl;
	}
	return 0;
}
