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
struct t1{
    int time, cid, pid, st;

    bool operator < (const t1 &e){
        return time < e.time;
    }
};
int t, n, s, p;


struct tt {
    int index, pen, ac;
    
    bool operator < (const tt &e){
        if (ac > e.ac)return 1;
        if (ac == e.ac && pen < e.pen)return 1;
        if (pen == e.pen && index < e.index) return 1;
        return 0;
    }
};
int main(){
    fast();
    cin >> t;
    while (t--){
        cin >> n >> p >> s;
        vector< t1 > a[105];
        tt res[101];
        for (int i = 1; i <= n; i++){
            res[i].index = i;
            res[i].ac = 0;
            res[i].pen = 0;
        }
        int vis[105][15];
        memset(vis, 0, sizeof vis);
    
        for(int i = 0 ; i < s;i++){
            t1 v;
            cin >> v.time >> v.cid >> v.pid >> v.st;
            a[v.cid].push_back(v);
        }
        for(int i = 1 ; i <=n;i++){
            sort(a[i].begin(), a[i].end());
        }
        for(int i = 1 ; i <=n;i++){
            for(int j = 0 ; j < (int)a[i].size();j++){
                if (a[i][j].st == 1 && vis[i][a[i][j].pid]!=-1){
                    tt tmp = res[i];
                    tmp.ac++;
                    tmp.pen += ((vis[i][a[i][j].pid] * 20) + a[i][j].time);
                    res[i] = tmp;
                    vis[i][a[i][j].pid] = -1;
                }
                else if (a[i][j].st == 0 && vis[i][a[i][j].pid] != -1){
                    vis[i][a[i][j].pid]++;
                }
            }
        }
        sort(res+1, res + n+1);
        for (int i = 1; i <= n;i++){
            cout << res[i].index << " " << res[i].ac << " " << res[i].pen;
            if (t || i + 1 <= n)cout << endl;
        }
    }

    return 0;
}
//mosta7il_
