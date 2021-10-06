#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f;
int dp[10001];
int mod = 10000007;
int fn(int n) {
    if (n == 0) return a%mod;
    if (n == 1) return b%mod;
    if (n == 2) return c%mod;
    if (n == 3) return d%mod;
    if (n == 4) return e%mod;
    if (n == 5) return f%mod;
    if(~dp[n])
        return dp[n];
    
    return dp[n] = (((((fn(n-1)%mod  + fn(n-2)%mod)%mod + fn(n-3)%mod)%mod
                   + fn(n-4)%mod)%mod + fn(n-5)%mod)%mod + fn(n-6)%mod)%mod;
}
int main() {
    int n, cases;
    cin>>cases;
    for (int caseno = 1; caseno <= cases; ++caseno) {
        memset(dp, -1, sizeof dp);
        cin>>a>>b>>c>>d>>e>>f>>n;
        printf("Case %d: %d\n", caseno, fn(n) % mod);
    }
    return 0;
}
