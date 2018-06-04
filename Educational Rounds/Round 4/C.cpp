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
const int MAX = 2 * 1000 * 100 + 1;

string s;
stack<char> st;

int fun(char x){
	return (x == '{' || x == '<' || x == '(' || x=='[') ? 1 : 2;
}
bool same(char x , char y){
	return (x == '{' && y == '}') || (x == '(' && y == ')')
		|| (x == '['&&y == ']') || (x == '<'&&y == '>');
}
int main(){
	fast();
	cin >> s;
	int cnt = 0;
	for (auto i : s){
		if (fun(i) == 1){
			st.push(i);
		}
		else{
			if (st.size() == 0){
				cout << "Impossible\n";
				return 0;
			}
			if (!same(st.top(), i)){
				cnt++;
			}
			st.pop();
		}
	}
	if (st.size()){
		cout << "Impossible\n";
		return 0;
	}

	cout << cnt << endl;
	return 0;
}
