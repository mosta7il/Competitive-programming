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
#include<cstring>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long long         ll;
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef vector<ll>		  vll;


const ll OO = 1e9+10;
const ll mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif
    std::ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}

int n  ,q;
int a[100*1000+2];
struct Node{
    int zero , one , two;
    
} tree[20 * 100*1000 +2 ];
int lazy[20 * 1000 * 100 +2];
void build(int cur ,int l  ,int r){
    if(l == r){
        tree[cur].zero = 1;
        tree[cur].one = 0;
        tree[cur].two = 0;
        return ;
    }
    int mid = (l+r)/2;
    int left = cur * 2;
    int right = left +1;
    build(left , l , mid);
    build(right , mid+1 , r);
    
    tree[cur].zero = tree[left].zero  + tree[right].zero;
    tree[cur].two = tree[left].two  + tree[right].two;
    tree[cur].one = tree[left].one  + tree[right].one;

}
void lazyness(int cur){
     int tmp0 = tree[cur].zero;
       tree[cur].zero = tree[cur].two;
       tree[cur].two = tree[cur].one;
       tree[cur].one = tmp0;
}
void prop(int cur , int l , int r){
    if(lazy[cur] ){
        lazy[cur] %= 3;
        for(int i = 0 ; i < lazy[cur] ; i++)
            lazyness(cur);
        if(l != r){
           lazy[cur*2] += lazy[cur];
           lazy[cur*2+1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
}
void update(int cur , int l , int r , int x , int y){
    prop(cur , l , r);
    if(x <= l && y >= r){
        int tmp0 = tree[cur].zero;
       tree[cur].zero = tree[cur].two;
       tree[cur].two = tree[cur].one;
       tree[cur].one = tmp0;
       if(l != r){
           lazy[cur*2]++;
           lazy[cur*2+1]++;
       }
       return ;
    }
    if(r < x || l > y)
    return;
    
    int mid = (l+r)/2;
    int left = cur * 2;
    int right = left +1;
    update(left , l , mid , x ,y);
    update(right , mid+1 , r , x ,y);
    tree[cur].zero = tree[left].zero  + tree[right].zero;
    tree[cur].two = tree[left].two  + tree[right].two;
    tree[cur].one = tree[left].one  + tree[right].one;
}

int query(int cur , int l , int r , int x , int y){
    prop(cur , l , r);
    if(x <= l && y >= r){
        return tree[cur].zero;
    }
    if(r < x || l > y)
        return 0;
    int mid = (l + r) /2;
    int left = cur * 2;
    int right = left +1;
    return query(left , l , mid , x , y) + query(right , mid + 1 , r , x ,y);
}
int main() {
   fast();
   cin>>n>>q;
   build( 1 , 1, n);
   for(int i = 0 ; i < q;i++){
       int t , x , y;
       cin>>t>>x>>y;
       y++;x++;
       if(t){
           cout<<query(1 , 1 , n , x , y)<<endl;
       }else{
           update( 1 , 1 , n , x , y);
       }
   }
  
    return 0;
}


