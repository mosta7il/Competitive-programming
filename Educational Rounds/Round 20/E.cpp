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
#define MAX  1 * 1000+5
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
string s;
int dp[MAX][2 * MAX];

bool rec(int idx, int sum){
	if (idx == n){
		return (abs(sum - k) == k);
	}
	if (abs(sum - k) == k&&idx != 0)
		return 0;
	int &ret = dp[idx][sum];
	if (~ret)
		return ret;
	ret = 0;
	if (s[idx] == 'W')
		ret |= rec(idx + 1, sum + 1);
	else if (s[idx] == 'D')
		ret |= rec(idx + 1, sum);
	else if (s[idx] == 'L')
		ret += rec(idx + 1, sum - 1);
	else{
		for (int i = -1; i <= 1; i++){
			ret |= rec(idx + 1, sum + i);
		}
	}
	return ret;
}

void build(int idx, int sum){
	if (idx == n){
		return;
	}
	
	if (s[idx] == 'W')
		return cout<<"W" , build(idx + 1, sum + 1);
	else if (s[idx] == 'D')
		return cout<<"D" , build(idx + 1, sum);
	else if (s[idx] == 'L')
		return cout<<"L" , build(idx + 1, sum - 1);
	else{
		for (int i = -1; i <= 1; i++){
			if (rec(idx + 1, sum + i)){
				if (i == -1)cout << "L";
				else if (i == 0) cout << "D";
				else cout << "W";
				build(idx + 1, sum + i);
				return;
			}
		}
	}
}
int main(){
	fast();
	memset(dp, -1, sizeof dp);
	cin >> n >> k >> s;
	int ret = rec(0, k);
	if (ret){
		build(0, k);
	}
	else cout << "NO\n";
	return 0;
} 
