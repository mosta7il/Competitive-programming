#include<iostream>
#include<vector>
using namespace std;

void main(){

	int n;
	vector<char>v;
	cin >> n;

	for (int r = 0; r <= n; r++){
		for (int s = 0; s <(n*2)-(r*2); s++){
			cout << " ";
		}
		for (int N = 0; N <= r; N++){
			v.push_back(N);
			cout << N ;
			if (r != 0){
				cout << " ";
			}
		}
		for (int w = v.size() - 2; w >= 0; w--){
			cout << (char)(v.at(w)+48);
			if (w - 1 >=0 ){
				cout << " ";
			}
		}
		v.clear();
		cout << endl;
	}
	for (int r = 0; r < n; r++){
		for (int s = 0; s < (r * 2) + 2; s++){
			cout << " ";
		}
		for (int N = 0; N <= (n - 1) - r; N++){
			v.push_back(N);
			cout << N;
			if ((n - 1) - r != 0){
				cout << " ";
			}
		}
		for (int w = v.size() - 2; w >= 0; w--){
			cout << (char)(v.at(w) + 48);
			if (w - 1 >= 0){
				cout << " ";
			}
		}
		v.clear();
		if (r + 1 < n){
			cout << endl;
		}
	}

}
