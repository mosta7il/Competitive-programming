#include<iostream>
#include<algorithm>
using namespace std;
struct t{
	int v, i;
};
void Z1(t a[], int n, int x, long long &c1, long long &c2){
	int l = 0, h = n - 1;
	 int mid;

	 while (l <= h){
		 mid = (l + h) / 2;
		 if (a[mid].v>x){
			 h = mid - 1;
		 }
		 else if (a[mid].v < x){
			 l = mid + 1;
		 }
		 else{
			 c1 += a[mid].i + 1;
			 c2 += n - a[mid].i;
			 return;
		 }
	 }

}

int Z2(int a[], int n, int x){
	int i;
	for (i =n-1; i >=0; i--){
		if (x == a[i])
			return n-i;
	}
	return n;
}

bool acompare(t lhs, t rhs) { return lhs.v < rhs.v; }
void main(){
	int n, k, *v;
	long long c1 = 0, c2 = 0;
	cin >> n;
	t *a = new t[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].v;
		a[i].i = i;
	}
	
	cin >> k;
	v = new int[k];
	for (int i = 0; i < k; i++){
		cin >> v[i];
	}
	sort(a, a + n, acompare);
	
		for (int i = 0; i < k; i++){
			Z1(a, n,v[i] ,c1 ,c2);
			
		}
		cout << c1 << " " << c2;
}
