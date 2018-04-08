#define _CRT_SECURE_NO_WARNINGS
// Do not work at uva or spoj..
#include<bits\stdc++.h> 
using namespace std;

const long long OO = 1000;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
map<long long, long long>mem;
long long rec(int n){
	if (n == 0){
		return 0;
	}
	if (mem.find(n) != mem.end())
		return mem[n];
	long long ret = 0;
	ret = rec(0) + n;
	ret = max(ret , rec(n / 2) + rec(n / 3) + rec(n / 4));
	return mem[n] = ret;
}
int main() {
	fast();
	long long n;
	while (cin >> n){
		cout << rec(n) << endl;
	}
	return 0;
}
