#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

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
const long long MAX = 20 *1000 * 1000 + 1;
struct edge{
	int cost,  to;
	edge(int w, int x){
		cost = w; to = x;
	}

	bool operator < (const edge& e)const{
		return cost > e.cost;
	}
};

int x, y, xx, yy, n;
map< pair< int, int>, bool>mp;
map<pair<int, int>, int> dist;
bool isv(int i, int j){
	return i >= 1 && j >= 1 && i <= 1e9 && j <= 1e9;
}
int main(){
	fast();
	
	cin >> x >> y >> xx >> yy;
	cin >> n;
	for (int i = 0; i < n; i++){
		int r, a, b;
		cin >> r >> a >> b;

		for (int j = a; j <= b; j++){
			mp[{r, j}] = 1;
		}
	}

	queue< pair<int, int> >q;
	q.push({ x, y });
	dist[{x, y}] = 0;
	while (q.size() > 0){
		auto cur = q.front();
		q.pop();
		if (make_pair(xx,yy) == cur)
			break;
		for (int i = 0; i < 8; i++){
			int ii = cur.first + dx[i], jj = cur.second + dy[i];
			if (isv(ii, jj) && mp.find({ ii, jj }) != mp.end() && dist.find({ ii, jj }) == dist.end()){
				dist[{ii, jj}] = dist[cur] + 1;
				q.push({ ii, jj });
			}
		}
	}

	if (dist.find({ xx, yy }) != dist.end())
		cout << dist[{xx, yy}] << endl;
	else cout << -1 << endl;
	return 0;
}
