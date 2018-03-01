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


const ll OO = 1e9+1;
const ll mod = 1e9+9;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

void fast(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n , k;
int A[10] ;
string s;
string ans;
int main(){
	fast();
        cin>>n>>k;
        cin>>s;
        lp(i , s.size()){
                A[s[i]-'0']++;
        }
        ll mn = 1e14;
        for(int i = 0 ; i <= 9;i++){
                ll l = i-1 ,cost = 0, r = i+1;
                int B[10]={0};
                int tmp[10];
                lp(j , 10)
                tmp[j] = A[j];
                int rem = k - A[i];
                while(rem > 0){
                        if(r <=9){
                                rem-=B[r] = min(rem , A[r] );
                                cost+=(r - i)*B[r]; 
                        }
                        if(rem <= 0)break;
                        if(l >= 0){
                                rem-=B[l] = min(rem , A[l]);
                                cost+=(i - l)*B[l];
                        }
                        r++;l--;
                }
                if(cost < mn){
                        ans.clear();
                        mn =cost;
                        lp(j , s.size()){
                                if(B[s[j]-'0']){
                                        if(tmp[s[j]-'0'] == B[s[j]-'0']){
                                               ans.push_back(i+'0');
                                                tmp[s[j]-'0']--;
                                                B[s[j]-'0']--;
                                        }else{
                                                if(s[j]> i+'0'){
                                                          ans.push_back(i+'0');
                                                          tmp[s[j]-'0']--;
                                                         B[s[j]-'0']--;
                                                }else{
                                                 ans.push_back(s[j]);
                                                       tmp[s[j]-'0']--;  
                                                }
                                        }
                                }else ans.push_back(s[j]);
                        }
                }else if(cost == mn){
                        string tt = "";
                        lp(j , s.size()){
                                if(B[s[j]-'0']){
                                        if(tmp[s[j]-'0'] == B[s[j]-'0']){
                                               tt.push_back(i+'0');
                                                tmp[s[j]-'0']--;
                                                B[s[j]-'0']--;
                                        }else{
                                                if(s[j]> i+'0'){
                                                          tt.push_back(i+'0');
                                                          tmp[s[j]-'0']--;
                                                         B[s[j]-'0']--;
                                                }else{
                                                 tt.push_back(s[j]);
                                                       tmp[s[j]-'0']--;  
                                                }
                                        }
                                }else tt.push_back(s[j]);
                        }
                        ans=min(ans,tt);
                }
        }
        cout<<mn<<endl;
        lp(i , ans.size())
        cout<<ans[i];
        cout<<endl;
	return 0;
}
//mosta7il_;
