#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<queue>
#include<map>
#include<fstream>


using namespace std;
char s[1001001];
vector < pair<int, long double> >v;
bool cmp(pair<int, long double> i, pair<int, long double>j){
	if (i.second < j.second)
		return 1;
	return 0;
}
int main(){
	ifstream fin("input.in");
	ofstream fout("output.out");
	
	scanf("%s", s);
	vector<int> a, b;
	for (int i = 0; s[i]; i++){
		
		if (s[i] == 'l'){
				a.push_back(i + 1);
		}
		else{
			b.push_back(i + 1);
		}
	}
	for (int i = 0; i < b.size(); i++){
		cout << b[i] << endl;
	}
	for (int i = a.size() - 1; i >=0; i--){
		cout <<  a[i] << endl;
	}
	return 0;
}
// mosta7il_
