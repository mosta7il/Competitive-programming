#include<iostream>
#include<cctype>
#include<string>
using namespace std;
bool Z(string s){
	for (int i = 1; i < s.size(); i++){
		if (!isupper(s.at(i))){
			return false;
		}
	}
	return true;
}
void main(){
	string s;
	cin >> s;
	if (Z(s)){
		if (isupper(s[0])){
			cout << (char)tolower(s[0]);
		}
		else{
			cout << (char)toupper(s[0]);
		}
		for (int i = 1; i < s.size(); i++){
			cout <<(char) tolower(s[i]);
			
		}

		return;
	}
	else{
		cout << s;
	}

}
