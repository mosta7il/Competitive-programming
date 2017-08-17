#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<queue>

using namespace std;
int a[4][4];
int main(){
	int s1 = 0, s2 = 0, s3 = 0 , sum = 0;
	int mxi = -1, mx = 0, mn = 1e5 + 1, mni = -1;
	for (int i = 0; i < 3; i++){
		sum = 0;
		for (int j = 0; j < 3; j++){
			cin >> a[i][j];
			sum += a[i][j];
			
		}
		if (i == 0)
			s1 = sum;
		else if (i == 1)
			s2 = sum;
		else if (i == 2)
			s3 = sum;
		
	}
	int &x = a[0][0];
	int &y = a[1][1];
	int &z = a[2][2];
	
	for (int i = 1; i <= (int)(1e5); i++){
		y = abs(s1 - s2 + i);
		z = abs(s1 - s3 + i);
		if ((i + z == a[0][2] + a[2][0] )&& (s1 + i) == (s2+y) && (s1 + i) == (s3 + z)){
			x = i;
			break;
		}
	}


	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
