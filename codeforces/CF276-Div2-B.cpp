#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>

using namespace std;
int a[26];
int main(){

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		a[s[i] - 'a']++;
	}
	int cnt = 0;
	for (int i = 0; i <= 26; i++){
		if (a[i] % 2)
			cnt++;
	}

	if (cnt == 0 || cnt == 1){
		cout << "First\n";
	}
	else{
		if (--cnt % 2)
			cout << "Second\n";
		else
			cout << "First\n";
	}
	return 0;
}
