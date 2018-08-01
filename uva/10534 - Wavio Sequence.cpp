#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e7;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const long long MAX = 2 * 1000 + 1;

void doLIS(const vector<int> &S, vector<int> &LIS){
	vector<int> L(S.size());
	int lisCount = 0;
	for (int i = 0; i < S.size(); ++i)
	{
		int pos = lower_bound(L.begin(), L.begin() + lisCount, S[i]) - L.begin();
		L[pos] = S[i];
		if (pos == lisCount)
			++lisCount;
		LIS[i] = pos + 1;
	}
}
int main(){
	fast();
	
	int N;
	while (cin >> N)
	{
		vector<int> S(N);
		for (int i = 0; i < N; ++i)
			cin >> S[i];

		vector<int> LIS(N), LDS(N);
		doLIS(S, LIS);
		reverse(S.begin(), S.end());
		doLIS(S, LDS);
		reverse(LDS.begin(), LDS.end());

		int maxLIS = 0;
		for (int i = 0; i < LIS.size(); ++i){
			
			maxLIS = max(maxLIS, 2 * min(LIS[i], LDS[i]) - 1);
		}
		cout << maxLIS << endl;
	}
	return 0;
};
