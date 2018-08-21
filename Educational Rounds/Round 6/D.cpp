#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> Point;

const long long OO = 1e9;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

}
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 4 * 100 * 1000 + 5;

int n, m;
long long a[2001], b[2001];
map <  long long, pair< int, int> >mp;
long long suma, sumb , dif;
vector<int> ans;
int main() {
	fast();
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i], suma += a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i] , sumb+=b[i];

	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			mp[1ll * a[i] + a[j]] = { i, j };
		}
	}
	dif = abs(suma - sumb);
	int cnt = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			long long tmp = abs(suma - sumb + 2 * (b[i] - a[j]));
			if (dif > tmp){
				dif = tmp;
				ans.clear();
				ans.push_back(j); ans.push_back(i);
				cnt = 1;
			}
		}
	}

	for (int i = 0; i < m; i++){
		for (int j = i + 1; j < m; j++){
			long long tmp = suma - sumb + 2 * (b[i] + b[j]);
			auto idx = mp.lower_bound(tmp/2) ;
			if (idx != mp.end()){
				long long tt = abs(suma - sumb + 2 * (b[i] + b[j]) - 2 * (*(idx)).first);
				if (dif > tt){
					dif = tt;
					ans.clear();
					ans.push_back((*(idx)).second.first);
					ans.push_back(i); 
					ans.push_back((*(idx)).second.second);
					ans.push_back(j);
					cnt  = 2;
				}
			}
			if (idx != mp.begin()){
				idx--;
				long long tt = abs(suma - sumb + 2 * (b[i] + b[j]) - 2 * (*(idx)).first);
				if (dif > tt){
					dif = tt;
					ans.clear();
					ans.push_back((*(idx)).second.first);
					ans.push_back(i); 
					ans.push_back((*(idx)).second.second);
					ans.push_back(j);
					cnt = 2;
				}
			}
		}
	}

	cout << dif << endl;
	cout << cnt << endl;
	if (cnt <= 1){
		for (auto e : ans)
			cout << e+1 << " ";
		cout << endl;
	}
	else{
		cout << ans[0]+1 << " " << ans[1]+1 << endl
			<< ans[2]+1 << " " << ans[3]+1 << endl;
	}
	return 0;
}
