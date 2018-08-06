#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e7;
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
const long long MAX = 100  + 1;

vector< vector<int> > adjList, comps, dagList;
vector<int> inStack, lowLink, dfn, comp, inDeg, outDeg;
stack<int> stk;
int ndfn, cntSrc, cntSnk;

int N, M;
void tarjan(int node) {
	lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
	stk.push(node);

	for(auto &ch: adjList[node]) {
	
		if (dfn[ch] == -1) {
			tarjan(ch);
			lowLink[node] = min(lowLink[node], lowLink[ch]);
		}
		else if (inStack[ch])
			lowLink[node] = min(lowLink[node], dfn[ch]);
	}

	if (lowLink[node] == dfn[node]) {
		comps.push_back(vector<int>());
		int x = -1;
		while (x != node) {
			x = stk.top(), stk.pop(), inStack[x] = 0;
			comps.back().push_back(x);
			comp[x] = comps.size() - 1;
		}
	}
}

void scc() {
	int n =N;

	inStack.clear();	inStack.resize(n);
	lowLink.clear();	lowLink.resize(n);
	dfn.clear();		dfn.resize(n, -1);
	ndfn = 0;

	comp.clear(), comp.resize(n);
	comps.clear();

	for(int i = 0 ; i < n;i++)if (dfn[i] == -1)
		tarjan(i);
}

void computeCompGraph() {
	int csz = comps.size(), cntSrc = csz, cntSnk = csz;

	outDeg.clear();		outDeg.resize(csz);
	inDeg.clear();		inDeg.resize(comps.size());
	dagList.clear();		dagList.resize(csz);	

	for (int i = 0; i < (adjList).size(); i++)
	for (int j = 0; j < (adjList[i]).size(); j++) {
		int k = adjList[i][j];
		if (comp[k] != comp[i]) {
			dagList[comp[i]].push_back(comp[k]);	
			inDeg[comp[k]]++;
			outDeg[comp[i]]++;
		}
		
	}

}
int main(){
	fast();
	int t = 1;
	cin >> t;
	while(t--){
		cin >> N >> M;
		adjList.clear();	adjList.resize(N);
		for (int i = 0; i < M; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			adjList[u].push_back(v);
		}
		scc();
		computeCompGraph();
		int cnt = 0;
		for (int i = 0; i < comps.size(); i++){
			cnt += (inDeg[i] == 0);
		}
		cout << cnt << endl;
	}
	return 0;
}
