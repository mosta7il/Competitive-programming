#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)                ((v).begin()), ((v).end())
#define sz(v)                ((int)((v).size()))
#define clr(v, d)            memset(v, d, sizeof(v))
#define rep(i, v)        for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)
#define pb                    push_back
#define MP                    make_pair
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
typedef long long         ll;
typedef long double         ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef vector<ll>          vll;


const ll OO = 1e16;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
}
int n, m, t;
int main(){
    fast();
    cin >> t;
    while (t--){
        cin >> n >> m;
        vector<int> g[1001];
        int vis[1001];
        int level[1001];
        memset(level, -1, sizeof level);
        for (int i = 1; i < n; i++)cin >> vis[i];

        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);

        }
        queue<int> q;
        q.push(0);
        level[0] = 0;
        while (!q.empty()){
            int src = q.front();
            q.pop();
            for (int i = 0; i < g[src].size(); i++){
                if (!vis[g[src][i]]){
                    q.push(g[src][i]);
                    level[g[src][i]] = level[src] + 1;
                    vis[g[src][i]] = 1;
                }
            }
        }

        for (int i = 1; i < n; i++)cout << level[i] << " ";
        cout << endl;
    }

    return 0;
}
//mosta7il_
