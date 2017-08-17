#include<iostream>
using namespace std;

void main(){

	char a[101];
	bool t = false;

	cin >> a;

	int i = 0;
	while (a[i]){
		if (a[i] == 'H' || a[i] == 'Q' || a[i] == '9'){
			t = true;
			cout << "YES";
			return;
		}
		i++;
	}
	cout << "NO";
	
	
}
