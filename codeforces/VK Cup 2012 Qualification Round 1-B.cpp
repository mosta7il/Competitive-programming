#include<iostream>
#include<functional>
#include<algorithm>
#include<array>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n; int n1=0 , n2=0 ,n3=0, n4=0;
	int *v = new int [n]; int rem, cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		(v[i] == 1) ? n1++ : (v[i] == 2) ? n2++ : (v[i] == 3) ? n3++ : n4++;
	}
	cnt += n4;
	if (n3 > n1){
		cnt += n1;
		n3 -= n1;
		n1 = 0;
		cnt += n3;
	}
	else{
		cnt += n3;
		n1 -= n3;
		n3 = 0;
		
	}
	
		cnt += (n2*2) / 4;
		n2  = ((n2*2)%4)/2;
		if (n2 > 0){
			cnt++;
			n1 -= 2;
		}
		if (n1 > 0){
				cnt += n1 / 4;
				if (n1 % 4 != 0){
					cnt++;
				}
			}
	
	cout << cnt;
	return 0;
}
