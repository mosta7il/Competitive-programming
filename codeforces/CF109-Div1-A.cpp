#include<bits\stdc++.h>
const long long oo = 1e6+5;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;

long long a, b; vector<pair<int, int> >v;
bool cmp(pair<int, int>i, pair<int, int> j){
	if (i.first + i.second < j.first + j.second)return 1;
	return 0;
}
bool comp(pair<int, int>i, pair<int, int> j){
	if (i.second < j.second)return 1;
	return 0;
}
int main(){
	fast();
	cin >> n;
	for (long long i = 0; i < oo; i++){
		long long a = n - (i * 7);
		if (a >= 0 && a % 4 == 0){
			v.push_back({ a / 4, i });
		}
	}
	if (v.size() == 0){ cout << -1 << endl;
	return 0;
	}
	sort(v.begin(), v.end(), cmp);
	long long q = v[0].second + v[0].first; int j = 0;
	for ( j = 0; j < v.size(); j++){
		if (q < v[j].first + v[j].second)break;
	}
	sort(v.begin(), v.begin() + j, comp);
	for (int e = v[0].first; e > 0; e--)cout << 4;
	for (int e = v[0].second; e > 0; e--)cout << 7;
	return 0;
}
//mosta7il_
