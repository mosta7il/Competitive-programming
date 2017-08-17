#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

double vp, vd, t, f, c;
int main(){
	fast();
	int cnt = 0;
	cin >> vp >> vd >> t >> f >> c;
	if (vp >= vd){
		cout << 0 << endl;
		return 0;
	}
	while ((t * vp) < c){
		double x = (t * vp) / (vd - vp);
		if ((t + x)*vp >= c){
			break;
		}
		t += x + x + f;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
//mosta7il_
