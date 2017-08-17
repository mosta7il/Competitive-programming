#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int main(){
	fast();
	int n; cin >> n;
	string s; cin >> s;
	if (n % 2 == 0){
		for (int i = 1; i <= s.size(); i++){
			cout << s[i - 1];
			if (i % 2 == 0&&i+1<=s.size()){
				cout << "-";
			}
		}
	}
	else{
		cout << s[0];
		for (int i = 1 , c = -1; i < s.size(); c++,i++){
			cout << s[i];
			if (c % 2 == 0&&i+1<s.size()){
				cout << "-";
			}
		}
	}
	return 0;
}
//mosta7il_
