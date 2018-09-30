#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll x ;int n;
		cin>>x>>n;
		if(n == 1){
			cout<<x<<endl;
			continue;
		}

		ll div = x / (n-1);
		vector<ll>v(n , 0);
		for(int i = 1 ;i<n;i++)
			v[i] += div;
		v[0] = v[n-1] = div/2;
		v[0] += (div%2);
		ll rem = x %(n-1);
		int st = ((div %2 == 0)?0:n-1);
		bool f = (div %2 == 0);
		while(rem){
			v[st]++;
			rem--;

			if(f){
				st++;
			}else st--;
			if(st == n-1 || st == 0)
				f = !f;
		}

		for(int i = 0 ; i <n;i++)
			cout<<v[i] <<" ";
		cout<<endl;
	}
	return 0;
}
