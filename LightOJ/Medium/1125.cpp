#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e13
#define EPS 1e-10
#define MLOG 20
#define MAX 2* 1000 * 100 +2
const int mod = 1e8 + 7;
const int N = 5 * 100 * 100;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int t, n, m, q, d, cas;
int coins[202];
long long dp[202][12][22];
long long rec(int nidx, int midx, int rem){
    if(midx == m)
        return (rem == 0);
    if(nidx == n)
        return 0;
    
    long long &ret = dp[nidx][midx][rem];
    if(~ret)
        return ret;
    ret = rec(nidx + 1, midx + 1, (rem + coins[nidx]%d + d)%d);
    ret += rec(nidx + 1, midx, rem);
    return ret;
}
int main() {
	fast();

	cin >> t;
	while (t--){
		cout << "Case " << ++cas << ":\n";
		cin >> n >> q;

		for (int i = 0; i < n; i++)
			cin >> coins[i];
		
        while(q--){
            cin>>d>>m;
            memset(dp, -1, sizeof dp);
            cout<<rec(0, 0, 0)<<endl;
        }

	}
	return 0;
}
