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
int t, n, k, cas;
int indces[16][16];
int dp[(1<<16)][16];
int rec(int taken, int idx){
    if(idx == n){
        return 0;
    }
    int &ret = dp[taken][idx];
    if(~ret)
        return ret;
    ret = 0;
    for(int i = 0;i<n;i++){
        if(taken& (1<<i))continue;
        ret = max(ret, rec(taken | (1<<i), idx+1) + indces[idx][i]);
    }
    return ret;
}
int main() {
	fast();

	cin >> t;
	while (t--){
		cout << "Case " << ++cas << ": ";
		cin >> n;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                cin>>indces[i][j];
        memset(dp, -1, sizeof dp);
        cout<<rec(0, 0)<<endl;
	}
	return 0;
}
