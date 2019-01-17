/*


*/

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
#define EPS 1e-12
#define MLOG 20
#define MAX 2* 100 * 1000+5
const int mod = 998244353;

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
int n, k;
vector<int>can;
string s;

bool OK(int md){

	int lines = 0, idx = 0;
	while (lines < k && idx < n){

		int lo = lower_bound(can.begin(), can.end(), idx + md -1) - can.begin();
		if (lo >= can.size()){
			lo--;
		}
		if (idx + md -1< can[lo])
			lo--;
		if (lo < 0)
			return 0;
		if (can[lo] < idx)
			return 0;

		idx = can[lo]+1;
		lines++;
	}
	return (idx >= n && lines <= k);
}
int main(){
	fast();
	cin >> k;
	cin.ignore();

	getline(cin, s);
	n = s.size();
	for (int i = 0; i < n; i++){
		if (s[i] == ' '|| s[i] == '-'){
			can.push_back(i);
		}
	}
	can.push_back(n-1);

	int lo = 1, hi = n , ans = -1;
	while (lo <= hi){
		int md = lo + hi >> 1;
		if (OK(md)){
			hi = md - 1;
			ans = md;
		}
		else{
			lo = md + 1;
		}
	}

	cout << ans << endl;
	return 0;
} 
