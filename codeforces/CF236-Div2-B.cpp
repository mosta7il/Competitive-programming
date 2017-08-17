#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int dv[101];
bool si[1001];
void sieve(){
	si[0] = 1;
	si[1] = 1;
	for (int i = 2; i*i <= 1001; i++){
		if (!si[i]){
			for (int j = i + i; j < 1001; j *= i){
				si[j] = 1;
			}
		}
	}
}
int numofd(int w){

	int cnt = 0 , res = 1;
	if (w == 1)
		return 1;
	
	for (int j = 2; j<= w; j++){
		
		cnt = 0;
		if (!si[j]){
			while (w % j == 0){

				cnt++;
				w /= j;
			}
			res *= (cnt + 1);
		}
	}
	return res;
}
int main(){
	sieve();
	int a, b, c;
	long long sum = 0;
	cin >> a >> b >> c;
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= b; j++){
			for (int k = 1; k <= c; k++){
				sum += numofd(i*j*k);
				sum %= 1073741824;
			}
		}
	}
	cout << sum % 1073741824 << endl ;
	return 0;
}
