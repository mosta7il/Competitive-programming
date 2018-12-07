/*
	

*/

// Defualt Block
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e9
#define mod 1e9+7
#define EPS 1e-8
#define MLOG 30
#define MAX 10 * 100 * 1000+5

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
// Add any thing after that comment 
int n;
char s[5];
bool valid(int x, int y){
	return (1 <= x && x <= y && y <= n);
}
bool fun(int x, int y, int xx, int yy){

	if (!valid(x, xx) || !valid(y, yy))
		return 0;
	printf("? %d %d %d %d\n", x, y, xx, yy);
	fflush(stdout);
	scanf("%s", &s);
	return (strcmp(s, "YES") == 0);
}
string ans , tmp;
int main(){
	//fast();

	scanf("%d", &n);

	int curx = 1, cury = 1;
	for (int i = 0; i < n - 1; i++){
		if (fun(curx + 1, cury, n, n)){
			curx++;
			ans += "D";
		}
		else {
			cury++;
			ans += "R";
		}
	}
	int revx = n, revy = n;
	for (int i = 0;  i < n - 1; i++){
		if (fun(1, 1, revx , revy -1)){
			revy--;
			tmp += "R";
		}
		else{
			revx--;
			tmp += "D";
		}
	}

	reverse(tmp.begin(), tmp.end());
	ans += tmp;
	cout <<"! "<< ans << endl;
	cout << flush;
	return 0;
}
