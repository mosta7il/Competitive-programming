#include<iostream>
#include<string>
using namespace std;

void main(){
	string s;
	int n; int c = 0;
	cin >> n>>c;
	cin >> s;
	for (int j = 0; j < c; j++){
		for (int i = 0; i < n - 1;){
			if (s[i] == 'B' && s[i + 1] == 'G'){
				char x = s[i];
				s[i] = s[i + 1];
				s[i + 1] = x;
				i += 2;
				continue;
			}
			i++;
		}
	}
	cout << s;
}
