#include<iostream>
#include<string>
using namespace std;
int main() {

	char ch;
	int op=0, r=0 , mx = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '(')
			op++;
		else if (s[i] == ')'&&op >0) {
			
			op-- , r+=2;
		}
		
	}
		cout << r;
		//system("pause");
		return 0;
}
