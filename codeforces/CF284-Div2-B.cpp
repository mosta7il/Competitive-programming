#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	char *a;
	int n, A=0, I=0, F = 0;
	cin >> n;
	a = new char[n + 1];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 'A')
			A++;
		else if (a[i] == 'I')
			I++;
		else
			F++;
	}
	if (I == 0)
		cout << A << endl;
	else if (I == 1)
		cout << 1 << endl;
	else{
		cout << 0 << endl;
	}
	return 0;
}
