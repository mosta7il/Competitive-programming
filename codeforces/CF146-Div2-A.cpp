#include<iostream>
#include<string>
using namespace std;
bool isLucky(string s){
	for (int i = 0; i < s.size(); i++){
		if (s[i] != '4' && s[i] != '7'){
			return false;
		}
	}
	return true;
}
bool sumd(string s){
	int f = 0, sec = 0;
	for (int i = 0; i < s.size() / 2; i++){
		f += s[i] - 48;
	}
	for (int j = s.size() / 2;j < s.size(); j++){
		sec += s[j] - 48;
	}
	return (f == sec);
}
int main(){
	string s;
	int n;
	cin >> n;
	cin >> s;
	if (isLucky(s) && sumd(s)){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}
