#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class UnsealTheSafe {
public:
	int g[4][3];
	long long mem[4][3][31];
	bool isv(int i, int j){
		return(i >= 0 && i < 4 && j >= 0 && j < 3 && g[i][j] <= 10);
	}
	long long rec(int i, int j, int cnt){
		if (cnt == 1){
			return 1;
		}
		long long &ret = mem[i][j][cnt];
		if (ret != -1)
			return ret;
		ret = 0;
		for (int idx = -1; idx <= 1; idx++){
			for (int idx1 = -1; idx1 <= 1; idx1++){
				if (abs(idx) == abs(idx1))continue;

				if (isv(idx + i, idx1 + j))
					ret += rec( (i + idx ), (j + idx1) , cnt - 1);
			}
		}
		return ret;
	}
	long long countPasswords(int N) {
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 3; j++){
				
				g[i][j] = (i)* 3 + (j+1);
			}
		}

		long long res = 0;
		fill(mem[0][0], mem[0][0]+ (4 * 3 * 31), -1);
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 3; j++){
				if (g[i][j] <= 10)
					res +=rec(i, j, N);
			}
		}
		return res;
	}
};
