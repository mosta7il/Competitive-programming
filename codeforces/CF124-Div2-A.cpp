#include<iostream>
#include<vector>
using namespace std;

void main(){
	int n , a ,b;
	cin >> n>>a>>b;
	vector<int>v;
	a++;
	if (b != 0){
		for (; a <= n&&b >= 0; a++, b--){
			v.push_back(a);
		}
		cout << v.size();
	}
	else{
		cout << 1;
	}
}
