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

int n , m , t ,q;
string s;
int a[15*1000*100 ];
//20444963.107493977132657621287391
int lazy[20544963+1];
pair<int , int> tree[20544963+1];
void build(int cur , int l , int r){
    tree[cur] = {0 , 0};
    if(l == r){
        tree[cur].first = (a[l] == 1);
        tree[cur].second = (a[l] == 0);
        return ;
    }
    int mid = (l + r)/2;
    int left = cur *2;
    int right = left + 1;
    build(left , l , mid);
    build(right , mid+1 , r);
    tree[cur].first = tree[left].first + tree[right].first;
    tree[cur].second = tree[left].second + tree[right].second;
}

void morelazyness(int cur , int v){
        if(lazy[cur] == -1){
             lazy[cur] = v;
        }
         
        else if(lazy[cur] <=2 && v <=1){
            lazy[cur] = v;
        } 
        
        else if(lazy[cur] <= 1 && lazy[cur]>=0 && v == 2){
            lazy[cur] = !lazy[cur];
        }else if(lazy[cur] ==2 && v == 2){
            lazy[cur]=-1;
        }
        
}
void lazyness(int cur , int l , int r , int v){
    // morelazyness(cur , v);
    if(v == 0){
        tree[cur].first = 0;
        tree[cur].second = (r-l+1);
    }else if(v==1){
        tree[cur].second = 0;
        tree[cur].first = (r-l+1);
    }else{
        swap(tree[cur].first , tree[cur].second);
    }
    if(l != r){
      morelazyness(cur*2 , v);
      morelazyness(cur*2+1 ,v );
    }
}
void prop(int cur , int l , int r){
    if(lazy[cur]!= -1){
        lazyness(cur , l , r , lazy[cur]);
        lazy[cur]=-1;
    }
}
void update(int cur , int l , int r , int x , int y,int v){
    prop(cur , l , r);
    if(x <= l && y>=r){
        lazyness(cur , l , r , v);
        return ;
    }
    
    if(y<l|| x>r){
        return;
    }
     int mid = (l + r)/2;
    int left = cur *2;
    int right = left + 1;
    update(left , l , mid , x , y ,v);
    update(right , mid+1 ,r, x , y, v);
    tree[cur].first = tree[left].first + tree[right].first;
    tree[cur].second = tree[left].second + tree[right].second;
}

int query(int cur , int l , int r ,int x, int y){
    prop(cur , l , r);
    if(x <= l && y>= r){
        return tree[cur].first;
    }
    
     if(y<l|| x>r){
        return 0;
    }
    int mid = (l + r)/2;
    int left = cur *2;
    int right = left + 1;
    return (query(left , l , mid , x ,y) + query(right , mid+1 , r , x , y));
}

int main() {
   fast();
   int T , idx = 1 , idx2 = 0;;
   cin>>T;
   while(T--){
       idx2 = 0;
       
      memset(lazy , -1 , sizeof lazy);
       cout<<"Case "<<idx++<<":\n";
       cin>>m;
       n=1;
       for(int i = 1 ; i<= m ;i++){
           cin>>t;
           cin>>s;
           for(int j = 1 ; j <= t; j++){
               for(int w = 0;w<(int)s.size();w++)
                a[n++] = (s[w]-'0');
           }
       }
       n--;
       build(1 , 1 , n);
       cin>>q;
       for(int i = 0;i<q;i++){
           char c;
           int x , y;
           cin>>c>>x>>y;
           x++,y++;
           if(c == 'F'){
               update(1 , 1 , n , x,y , 1);
           }else if(c == 'E'){
               update(1 , 1 , n , x , y, 0);
           }else if(c == 'I'){
               update(1 , 1 , n , x,y,2);
           }else{
               cout<<"Q"<<++idx2<<": "<<query(1 , 1 , n , x , y)<<endl;
           }
       }
   }
    return 0;
}
