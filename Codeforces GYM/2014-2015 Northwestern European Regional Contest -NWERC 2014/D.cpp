#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-11);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

const  long long  OO = 1e9;
const long long mod = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ld long double
void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("point3.in", "r", stdin);
	//freopen("point3.out", "w", stdout);
}
const long long MAX = 500 * 1000 + 5;

long long n;
int m;
long long cnt[MAX];
int IND[MAX], L[MAX], R[MAX];
char state[MAX];
bool vis[MAX];
int main() {
	fast();
	cin >> n >> m;

	for (int i = 1; i <= m; i++){
		cin >> state[i] >> L[i] >> R[i];
		IND[L[i]]++;
		IND[R[i]]++;
	}
	queue<int>q;
	for (int i = 1; i <= m; i++){
		if (IND[i] == 0){
			q.push(i);
			vis[i] = 1;
		}
	}
	cnt[1] = n;
	while (q.size() > 0){
		int cur = q.front();
		q.pop();
		if (cur == 0)
			continue;
		cnt[L[cur]] += (cnt[cur] / 2);
		cnt[R[cur]] += (cnt[cur] / 2);
		if (state[cur] == 'L')cnt[L[cur]] += (cnt[cur] % 2);
		else cnt[R[cur]] += (cnt[cur] % 2);
		IND[L[cur]]--;
		IND[R[cur]]--;
		if (IND[L[cur]] == 0){
			vis[L[cur]] = 1;
			q.push(L[cur]);
		}
		if (!vis[R[cur]] && IND[R[cur]] == 0){
			vis[R[cur]] = 1;
			q.push(R[cur]);
		}
	}

	for (int i = 1; i <= m; i++){
		if (cnt[i] % 2)
			state[i] = ((state[i] == 'L') ? 'R' : 'L');
		cout << state[i];
	}

	return  0;
}
