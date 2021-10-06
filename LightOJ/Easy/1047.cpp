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
int t, n, cs;
int dp[20][3];
int main() {
	fast();

    cin>>t;
    while(t--){
        cout<<"Case "<<++cs<<": ";
        cin>>n;
        for(int i = 0 ;i<n;i++){
            for(int j = 0;j<3; j++)
                cin>>dp[i][j];
        }
        int res = 1e9;
        for(int i = 1; i<n;i++){
            for(int j = 0; j<3; j++){
                int mn = 1e9;
                for(int k = 0; k<3; k++){
                    if(k == j)continue;
                    mn = min(mn, dp[i - 1][k]);
                }
                dp[i][j] += mn;
                if(i == n - 1)
                    res = min(res, dp[i][j]);
            }
        }
        cout<<res<<endl;

    }

	return 0;
}
