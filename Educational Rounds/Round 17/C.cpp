#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>


using namespace std;

typedef complex<double> Point;


const long long OO = 1e15;
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
const long long MAX = 100 * 1000 + 5;
string s, w;

vector<int> a[26], b[26];

int L[MAX], R[MAX];

int main() {
	fast();
	memset(R, -1, sizeof R);
	cin >> s >> w;

	for (int i = 0; i < s.size(); i++){
		a[s[i] - 'a'].push_back(i);
	}
	for (int i = s.size() - 1; i >= 0;i--)
		b[s[i] - 'a'].push_back(-i);

	int l = 0 , lst = -1;
	for (int i = 0; i < w.size(); i++){
		int idx = upper_bound(a[w[i] - 'a'].begin(), a[w[i] - 'a'].end(), lst) - a[w[i] - 'a'].begin();
		if (idx >= a[w[i] - 'a'].size()){
			break;
		}
		l = i+1;
		L[i] = a[w[i] - 'a'][idx];
		lst  = a[w[i] - 'a'][idx];
	}

	int r = w.size() -1;
	lst = s.size(); lst *= -1;
	for (int i = w.size() - 1; i >= 0; i--){
		int idx = upper_bound(b[w[i] - 'a'].begin(), b[w[i] - 'a'].end(), lst) - b[w[i] - 'a'].begin();
		if (idx >= a[w[i] - 'a'].size()){
			break;
		}
		r = i-1;
		R[i] = -b[w[i] - 'a'][idx];
		lst = b[w[i] - 'a'][idx];
	}

	int mx = ((int)w.size()) - r - 1; string res = w.substr(r+1);
	if (l >= ((int)w.size()) - r - 1){
		mx = l;
		res = w.substr(0, l);
	}

	for (int i = 0; i < l; i++){
		int idx = upper_bound(R, R + w.size(), L[i]) - R;
		if (idx >= w.size()|| idx <=i){
			continue;
		}
		if (i + 1 + (w.size() - idx) > mx){
			mx = (i + 1 + (w.size() - idx));
			res = w.substr(0, i+1) + w.substr(idx);
		}
	}
	if (res.empty())cout << "-\n";
	else cout << res << endl;
	return 0;
}
