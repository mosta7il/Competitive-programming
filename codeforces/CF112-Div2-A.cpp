#include<iostream>
#include<string>
using namespace std;

void main(){
	char s1[102], s2[102];

	cin >> s1 >> s2;
	int i = 0;
	for (; s1[i]; i++){
		s1[i] = tolower(s1[i]);
		s2[i] = tolower(s2[i]);

	}
	int t = strcmp(s1, s2);
	if (t > 0){
		cout << 1;
	}
	else if (t < 0){
		cout << -1;
	}
	else{
		cout << 0;
	}
}
