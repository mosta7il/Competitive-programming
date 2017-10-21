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


const ll OO = 1e16;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
vector<int> a[26];
int b[26];
int n;

int main(){
	fast();
	ofstream ff("pp.txt");
	cin >> n;
	lp(i, n){
		a[i].push_back(i);
		b[i] = i;
	}

	cin.ignore();
	string s;
	while (getline(cin, s) && s != "quit"){
		stringstream ss;
		ss << s;
		string tmp;
		ss >> tmp;
		if (tmp == "move"){
			int x, y;
			ss >> x >> tmp >> y;
			int inx = b[x], iny = b[y];
			if (inx == iny || x == y)continue;
			if (tmp == "onto"){
				for (int i = a[inx].size() - 1; i >= 0; i--){
					if (a[inx][i] == x){
						break;
					}
					b[a[inx][i]] = a[inx][i];
					a[a[inx][i]].push_back(a[inx][i]);
					a[inx].pop_back();

				}

				for (int i = a[iny].size() - 1; i >= 0; i--){
					if (a[iny][i] == y)break;
					b[a[iny][i]] = a[iny][i];
					a[a[iny][i]].push_back(a[iny][i]);
					a[iny].pop_back();
				}
				if (x == 12 && y == 18){
					fast();
				}
				b[x] = iny;
				
				a[inx].pop_back();
				a[iny].push_back(x);
				
			}
			else if (tmp == "over"){
				for (int i = a[inx].size() - 1; i >= 0; i--){
					if (a[inx][i] == x)break;
					b[a[inx][i]] =a[inx][i];
					a[a[inx][i]].push_back(a[inx][i]);
					a[inx].pop_back();

				}
				b[x] = iny;
			
				a[inx].pop_back();
				a[iny].push_back(x);
			}
		}
		else {
			int xx, yy;
			ss >> xx >> tmp >> yy;
			int ix = b[xx], iy = b[yy];
			if (ix == iy || xx == yy)continue;
			if (tmp == "onto"){
				for (int i = a[iy].size() - 1; i >= 0; i--){
					if (a[iy][i] == yy){
						break;
					}
					b[a[iy][i]] = a[iy][i];
					a[a[iy][i]].push_back(a[iy][i]);
					a[iy].pop_back();
				}
				stack<int>st;
				for (int i = a[ix].size() - 1; i >= 0; i--){
					if (a[ix][i] == xx){
						b[a[ix][i]] = iy;
						st.push(a[ix][i]);
						a[ix].pop_back();
						break;
					}
					b[a[ix][i]] = iy;
					st.push(a[ix][i]);
					a[ix].pop_back();
				}
				while (!st.empty()){
					a[iy].push_back(st.top());
					st.pop();
				}
			}
			else if (tmp == "over"){
				stack<int>st;
				for (int i = a[ix].size() - 1; i >= 0; i--){
					if (a[ix][i] == xx){
						b[a[ix][i]] = iy;
						st.push(a[ix][i]);
						a[ix].pop_back();
						break;
					}
					b[a[ix][i]] = iy;
					st.push(a[ix][i]);
					a[ix].pop_back();
				}
				while (!st.empty()){
					a[iy].push_back(st.top());
					st.pop();
				}
			}
			
		}
	}
	lp(w, n){
		cout << w << ":";
		rep(j, a[w]){
			cout << " "<<a[w][j];
		}
			cout << endl;
	}
	return 0;
}
//mosta7il_
