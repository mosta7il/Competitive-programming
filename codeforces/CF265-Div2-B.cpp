#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	int h = 0, res = 0, n;
	cin >> n;
	res = n + n - 1;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++){
		res += abs(a[i] - h);
		h = a[i];
	}
	cout << res << endl;
	return 0;
}
