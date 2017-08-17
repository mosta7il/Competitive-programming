#include<iostream>
#include<string>
#include<sstream>
using namespace std;
bool isV(char x){
	switch (x){
	case 'o':
	case'a':
	case'y':case'i':case'e':case'u':return true; break;
	}
	return false;
}
void main(){
	string s , l="";
	stringstream ss;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++){
		l += tolower(s[i]);
	}

	for (int i = 0; i < l.size(); i++){
		if (!isV(l[i])){
			ss << '.' << l[i];
		}
	}
	cout << ss.str();
}
