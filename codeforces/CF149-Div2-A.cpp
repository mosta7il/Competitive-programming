#include<iostream>
#include<algorithm>
using namespace std;

void main(){
	int k;
	cin >> k;

	int *a = new int[12];

	for (int i = 0; i < 12; i++){
		cin >> a[i];
	}
	sort(a, a + 12);
	if (k != 0){
		int w = 11, c = 0, sum = 0;
		while (sum < k &&w >= 0){
			sum += a[w];
			c++;
			w--;
		}

		if (sum<k){
			cout << -1; return;
		}
		else{
			cout << c; return;
		}
	}
	else{
		cout << 0; return;
	}
}
