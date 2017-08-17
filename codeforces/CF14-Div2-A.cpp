#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct t {
	int index, s, e;
};
int min_s(vector<t>v){
	int min;
	for (int i = 0; i < v.size(); i++){
		if (v.at(i).s >= 0){
			 min = v.at(i).s;
			break;
		}
	}
	for (int i = 0; i < v.size(); i++){
		if (min >v.at(i).s && v.at(i).s >=0){
			min = v.at(i).s;
		}
	}
	return min;
}
int max_e(vector<t>v){
	int min;
	for (int i = 0; i < v.size(); i++){
		if (v.at(i).e >= 0){
			min = v.at(i).e;
			break;
		}
	}
	for (int i = 0; i < v.size(); i++){
		if (min <v.at(i).e ){
			min = v.at(i).e;
		}
	}
	return min;
}
void main(){
	int n, m;
	vector<t>v;
	t x;
	cin >> n >> m;
	string *a = new string[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int c = 0;
	for (int i = 0; i < n; i++){
		x.index = i;
		x.s = -1;
		x.e = -1;
		for (int j = 0; j < m; j++){
			if (a[i][j] == '*'){
				if (c == 0){
					x.s = j;
					c++;
				}
				x.e = j;
				x.index = i;
			}
		}
		v.push_back(x);
		c = 0;
		}
	int last = n;
	bool t = false;
	int first = -1;
	for (int i = n - 1; i >= 0; i--){
		for (int j = 0; j < m; j++){
			if (a[i][j] == '*'){
				last = i;
				t = true;
				break;
			}
			
		}
		if (t){
			break;
		}
	}
	for (int i = 0; i <n; i++){
		t = false;
		for (int j = 0; j < m; j++){
			if (a[i][j] == '*'){
				first = i;
				t = true;
				break;
			}
			
		}
		if (t){
			break;
		}
	}
	int q = min_s(v);
	int j = max_e(v);
	for (int w = 0; w < n; w++){
		if ( w <= first - 1 || w >= last + 1){
			continue;
		}
		
		for (int i = q; i <= j;i++){
			cout << a[w][i];
			
		}
		cout << endl;
	}
	
}
