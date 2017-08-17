#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool contain(vector<int>v, int i){
	for (int w = 0; w < v.size(); w++){
		if (i == v.at(w))
			return true;
	}
	return false;
}
void main(){
	string s1, s2, s;
	vector<int>v1;
	cin >> s1 >> s2 >> s;
	
	if (s.size() - s1.size() - s2.size() != 0){
		cout << "NO"; return;
	}
	else{

		for (int i = 0; i < s1.size(); i++){
			for (int j = 0; j < s.size(); j++){
				if (s1[i] == s[j] && !contain(v1, j)){
					v1.push_back(j);
					break;
				}
			}
		}

		for (int i = 0; i < s2.size(); i++){
			for (int j = 0; j < s.size(); j++){
				if (s2[i] == s[j] && !contain(v1, j)){
					v1.push_back(j);
					break;
				}
			}
		}
		if (v1.size() == s.size()){
			cout << "YES"; return;
		}
	}
	cout << "NO";
}
