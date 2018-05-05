#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;
char d;
int sum;
string a[100 * 100 + 1];
deque<string> b[11];
int main() {
	fast();
	cin >> n;
	for (int i = 0; i< n; i++){
		cin >> a[i];
		sum += (int)a[i].size();
	}
	cin >> d;
	sort(a, a + n);
	for (int i = 0; i < n; i++){
		b[a[i].size()].push_back(a[i]);
	}
	int x = sum * 2 / n;
	
	for (int i = 0; i < n / 2; i++){
		pair< string, pair < int, int> > mn = { "{", { -1, -1 } };
		
		string tmp1, tmp2;
		for (int j = 1; j <=10; j++){
			pair< string, pair < int, int> > cur;
			if (b[j].size() == 0)
				continue;

			cur.first += b[j].front();
			tmp1 = b[j].front();
			b[j].pop_front();
			cur.second.first = j;
			cur.first += d;
			int rem = x - j;

			if (!(rem >= 1 && rem <= 10) || (b[rem].size() == 0)){
				b[j].push_front(tmp1);
				continue;
			}

			tmp2 = b[rem].front();
			b[rem].pop_front();
			cur.second.second = rem;
			cur.first += tmp2;
			
			if (cur.first < mn.first){
				mn = cur;
				b[rem].push_front(tmp2);
				b[j].push_front(tmp1);
				
			}
			else{
				b[rem].push_front(tmp2);
				b[j].push_front(tmp1);
			}
		}
		cout << mn.first << endl;
		b[mn.second.first].pop_front();
		b[mn.second.second].pop_front();
	}
	return 0;
}
