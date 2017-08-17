#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<long long> seive(){
	set<long long>w;
	bool arr[1000001] = { false };
	fill(arr, arr + 1000001, true);
	arr[0] = false; arr[1] = false;
	for (int i = 2; i*i < 1000001; i++){
		if (arr[i]){
			for (int j = i*i; j < 1000001; j += i){
				arr[j] = false;
			}
		}
	}

	for (int i = 2; i < 1000001; i++){
		if (arr[i]){
			w.insert((long long)i*i);
		}
	}
	return w;
}
int main(){
	int n;
	long long x;
	cin >> n;
	set<long long>s(seive());
	for (int i = 0; i < n; i++){
		cin >> x;
		if (s.find(x) != s.end()){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

	//system("pause");
	return 0;
}
