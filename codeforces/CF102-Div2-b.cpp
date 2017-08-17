#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int cont = 0;
	while (s.size() > 1){
		stringstream ss;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++){
			cnt += (s[i] - '0');
		}
		ss << cnt;
		s = ss.str();
		cont++;
	}
	cout << cont << endl;
	return 0;
}
