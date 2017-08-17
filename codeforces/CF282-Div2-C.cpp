#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

string a, b;
int main(){
	fast();
	cin >> a >> b;
	if (a.size() != b.size()){
		cout << "NO\n";
		return 0;
	}
	int on = 0, one = 0;
	for (int i = 0; i < a.size() ; i++){
		on += (a[i] == '0');
		one += (b[i] == '0');
	}
	if ((a.size()==on ||b.size()==one) &&(on !=one) ){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
	return 0;
}
//mosta7il_
