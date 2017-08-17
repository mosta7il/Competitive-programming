#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
vector<long long>v;
int bs(int l){
	int lo = 0, hi = v.size() - 1;
	while (lo < hi){
		int mid = lo + (hi - lo) / 2;
		if (v[mid] >= l){
			hi = mid;
		}
		else{
			lo = mid + 1;
		}
	}
	return hi;
}
int main(){
	fast();
	long long l, r; cin >> l >> r;
	v.push_back(4);
	v.push_back(7); int i = 0;
	while (v[v.size() - 1] <= oo){
		v.push_back((v[i] * 10) + 4);
		v.push_back((v[i] * 10) + 7);
		i++;
	}
	sort(v.begin(), v.end());
	int ind = bs(l);
	long long res = 0;
	if (r < 4){ cout << (r-l+1)*4 << endl; 
	return 0; }
	while (((ind==0)&&v[ind] <= r)||(ind>0 && v[ind-1]<=r)){
		res += (min(r, v[ind]) - l + 1)*v[ind];
		l = v[ind]+1; ind++;
	}
	cout << res << endl;
	return 0;
}
//mosta7il_
