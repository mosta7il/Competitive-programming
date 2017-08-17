#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, s, t, temp , c=0;
	cin >> n >> s >> t;
	int *p = new int[n];
	for (int i = 0; i < n; cin >> p[i++]);
	temp = s;
	if (s == t){
		cout << 0; return 0;
	}
	while (s != t){
		s = p[s - 1];
		c++;
		if (temp == s){
			cout << -1; return 0;
		}
	}
	cout << c << endl;
	return 0;
}
