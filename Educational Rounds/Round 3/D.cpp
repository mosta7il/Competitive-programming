#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1 , 1 , 1 , -1 , -1};
int dy[] = { 1, -1, 0, 0 ,1 ,-1 , 1 , -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 2 * 1000 * 100 + 1;
int n, m, k, s;
long long dollar[MAX], pound[MAX];
vector<pair<long long , int> > dollar_gadget, pound_gadget;
vector<pair<long long , int> > tmp_dollar, tmp_pound;
vector< pair<int, int > >ret;
bool fun(int md){
	tmp_dollar.clear();
	tmp_pound.clear();
	for (int i = 0; i < dollar_gadget.size(); i++){
		tmp_dollar.push_back(dollar_gadget[i]);
	}
	for (int i = 0; i < pound_gadget.size(); i++){
		tmp_pound.push_back(pound_gadget[i]);
	}
	long long mnp, mnd; int pidx = -1, didx = -1;
	mnp = mnd = 1e9;
	for (int i = 0; i <= md; i++){
		if (mnp > pound[i]){
			mnp = pound[i];
			pidx = i;
		}
		if (mnd > dollar[i]){
			mnd = dollar[i];
			didx = i;
		}
	}
	for (auto &i : tmp_dollar){
		i.first = i.first * mnd;
	}
	for (auto &i : tmp_pound){
		i.first = i.first * mnp;
	}
	vector<pair< int, pair<long long ,int> > >price;
	int i = 0, j = 0;
	while (i < tmp_dollar.size() && j < tmp_pound.size()){
		if (tmp_dollar[i].first <= tmp_pound[j].first){
			price.push_back({ 1, tmp_dollar[i] });
			i++;
		}
		else{
			price.push_back({ 2, tmp_pound[j] });
			j++;
		}
	}
	while (i < tmp_dollar.size()){
		price.push_back({ 1, tmp_dollar[i] });
		i++;
	}
	while (j < tmp_pound.size()){
		price.push_back({ 2, tmp_pound[j] });
		j++;
	}
	ret.clear();
	long long tot = 0;
	for (int i = 0; i < k; i++){
		tot += price[i].second.first;
		if (price[i].first == 1)
			 ret.push_back({ price[i].second.second, didx + 1 });
		else ret.push_back({ price[i].second.second, pidx + 1 });

		if (tot > s){
			return 0;
		}
	}
	return (tot <= s);
}
int main(){
	fast();
	cin >> n >> m >> k >> s;

	for (int i = 0; i < n; i++)
		cin >> dollar[i];
	for (int i = 0; i < n; i++)
		cin >> pound[i];
	int x, y;
	x = y = 0;
	for (int i = 0; i < m; i++){
		int type , price; cin >> type>>price;
		if (type == 1){
			dollar_gadget.push_back({price, i+1 });
		}								  
		else{							  
			pound_gadget.push_back({price , i+1});
		}
	}
	sort(dollar_gadget.begin(), dollar_gadget.end());
	sort(pound_gadget.begin(), pound_gadget.end());

	int lo = 0, hi = n-1, ans = -1;
	while (lo <= hi){
		int md = lo + (hi - lo) / 2;
		if (fun(md)){
			hi = md - 1;
			ans = md;
		}
		else{
			lo = md + 1;
		}
	}
	if (ans == -1)cout << ans << endl;
	else cout << ans + 1 << endl;
	if (ans != -1){
		fun(ans);
		for (auto x : ret){
			cout << x.first << " " << x.second << endl;
		}
	}
	return 0;
}
