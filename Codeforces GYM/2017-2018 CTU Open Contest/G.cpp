
#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;
#define angle(a) ( atan2( (a).imag(), (a).real()) )
#define ll long long

int n,m;
vector< map<int , bool> >v;
vector<int>L;
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n>>m){
		v.clear();v.resize(n);
		L.clear() , L.resize(n);
		for(int i = 0 ; i <n;i++){
			int l ; cin>>l;
			L[i] = l;
			while(l--){
				int x;cin>>x;
				v[i][x] = 1;
			}
		}
		int j = 0 ;
		ll cnt= 0;
		ll mn =1e18;map<int , int>mp; 
		for(int i = 0 ; i <n;i++){
			
			while(mp.size() < m){
				for(auto &e : v[j]){
					mp[e.first] += 1;
				}
				cnt+=L[j];
				j++;
				j %=n;
				if(i == j)break;
			}
			
			if(mp.size() == m){
				mn = min(cnt , mn);
			}
			cnt-=L[i];
			for(auto &e:v[i]){
				mp[e.first]--;
				if(mp[e.first] == 0)
					mp.erase(e.first);
			}
		}
			
		if(mn < 1e18)cout<<mn<<"\n";
		else cout<<-1<<"\n";
	}
	return 0;
}
