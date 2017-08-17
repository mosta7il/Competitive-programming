#include<bits\stdc++.h>
const int oo = 1e5+2;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int a[oo];
string s;
int main(){
	fast();
	cin >> s;
	for (int i = 1; i <= s.size()-1; i++){
		a[i] = (s[i-1] == s[i]);
	}
	for (int i = 1; i <= s.size(); i++){
		a[i] += a[i - 1];
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		cout << a[r - 1] - ((l - 1 < 0) ? 0 : a[l - 1]) << endl;
	}
	return 0;
}
//mosta7il_
