#include<iostream>
#include<string>
using namespace std;

void main(){

	string s;
	int c = 0, d = 0;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '4' || s[i] == '7'){
			c++;
		}
	}
	if (c == 0){
		cout << "NO";
		return;
	}
	while (c>0){
		d = c % 10;
		if (d != 4 && d != 7){
			cout << "NO";
			return;
		}
		c /= 10;
	}

	cout << "YES";
}
