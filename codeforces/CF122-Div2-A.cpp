#include<iostream>
using namespace std;
bool isLucky(int x){
	int dig = 0;
	while (x > 0){
		dig = x % 10;
		x /= 10;
		if (dig != 4 && dig != 7){
			return false;
		}
	}return true;
}
void main(){
	int x = 0;
	cin >> x;
	for (int i = 1; i <= x; i++){
		if (isLucky(i)&& (x%i == 0)){
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}
