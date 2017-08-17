#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct t{
	int v, i;
};
bool contain(vector<int>v, int x){
	for (int i = 0; i < v.size(); i++){
		if (x == v.at(i)){
			return true;
		}
	}
	return false;
}
int max(vector<t>v){
	t temp;
	temp.v = v.at(0).v;
	temp.i = v.at(0).i;
	for (int i = 0; i < v.size(); i++){
		if (temp.v < v.at(i).v){
			temp.v = v.at(i).v;
		}
	}
	return temp.v;
}
void main(){
	int n, m, w;
	cin >> n >> m;
	vector<t> v1;
	vector<int>v2; t temp;
	string *a = new string[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i <m; i++){
		for (int j = 0; j < n; j++){
			temp.v = a[j][i];
			temp.i = j;
			v1.push_back(temp);
		}
		///sort(v1.begin(), v1.end());
		w =max(v1);
		for (int i = 0; i < v1.size(); i++){
			if (w == v1.at(i).v && !contain(v2,i)){
				v2.push_back(i);
			}
		}
		v1.clear();
	}

	cout << v2.size();
}
