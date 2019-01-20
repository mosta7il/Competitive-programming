/*


*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e9
#define EPS 1e-12
#define MLOG 20
#define MAX  3 * 100  * 1000+5
const int mod = 1e9+7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){


	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

struct dsu{

	int g[MAX];
	dsu(int n){
		for (int i = 1; i <= n; i++)
			g[i] = i;
	}

	int root(int a){
		if (a == g[a])
			return a;
		return g[a] = root(g[a]);
	}

	void join(int a, int b){
		int ra = root(a),
			rb = root(b);
		g[ra] = rb;
		cout << "LADICA\n";
	}
};

int n , l;
int taken[MAX];
int main(){
	fast();
	cin >> n >> l;

	dsu tree(l);

	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if (!taken[a]){
			taken[a] = 1;
			tree.join(a, b);
		}
		else if (!taken[b]){
			taken[b] = 1;
			tree.join(b, a);
		}
		else if (!taken[tree.root(a)]){
			taken[tree.root(a)] = 1;
			tree.join(a, b);
		}
		else if (!taken[tree.root(b)]){
			taken[tree.root(b)] = 1;
			tree.join(b, a);
		}
		else{
			cout << "SMECE\n";
		}
	}
	return 0;
}
