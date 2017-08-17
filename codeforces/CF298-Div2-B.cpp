#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>

using namespace std;
void check(pair<char, char> &x, pair<int, int> &p, pair<int, int> &w){
	if (p.first < w.first)
		x.first = 'E';
	else if (p.first > w.first)
		x.first = 'W';
	else
		x.first = '.';


	if (p.second < w.second)
		x.second = 'N';
	else if (p.second > w.second)
		x.second = 'S';
	else
		x.second = '.';
}
void move(char x , pair<int,int> &p  ,pair<int , int>to){
	if (x == 'E'){
		if (to.first > p.first)
			p.first++;
	}
	else if (x == 'W'){
		if (to.first < p.first)
			p.first--;
	}
	else if (x == 'N'){
			if (to.second > p.second)
				p.second++;
	}
	else{
			if (to.second < p.second)
				p.second--;
	}
}
int main(){

	pair< char, char> g;
	int t, res = 0;
	pair<int, int>f ,to;
	string s;
	bool ar = 0;
	cin >> t >> f.first >> f.second >> to.first >> to.second;
	cin >> s;
	check(g, f, to);
	for (int i = 0; i < t; i++){
		if (s[i] == g.first || s[i] == g.second){
			move(s[i], f,to);
			
		}
		if (f == to){
			i = t;
			ar = 1;
		}
		res++;
	}
	if (ar)
		cout << res;
	else
		cout << -1;
	return 0;
}
