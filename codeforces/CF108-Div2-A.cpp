#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;
void p_(char h[2], char m[2]){
	int hr = atoi(h);
	int ms = atoi(m);
	ms = (ms + 1) % 60;
	if (ms == 0){
		hr = (hr + 1) % 24;
	}
	int c1 , pos ;
	c1 = 0; pos = 1;
	if (hr == 0){
		for (int i = 0; i<2; i++){
			h[i] = '0';
		}
	}
	if (ms == 0){
		for (int i = 0; i<2; i++){
			m[i] = '0';
		}
	}
	int d;
	bool t = true;
	while (hr > 0){
		d = hr % 10;
		hr /= 10;
		h[pos] = d+48;
		pos--;
		c1++;
		t= false;
	}
	if (c1 !=2&&!t){
		h[0] = 48;
	}

	pos = 1 , c1 = 0;
	t = true;
	while (ms > 0){
		d = ms % 10;
		ms /= 10;
		m[pos] = d + 48;
		pos--;
		c1++;
		t = false;
	}
	if (c1 != 2&&!t){
		m[0] = 48;
	}
	h[2] = NULL; m[2] = NULL;
}
bool Z(char h[], char m[]){

	for (int i = 0, j = 1; i < 2; i++, j--){
		if (h[i] != m[j]){
			return false;
		}
	}
	return true;
}
void main(){

	char h[2], m[2], x;
	string s;
	cin >> s;
	for (int i = 0, j = 2; i < s.size(); j--,i++){
		if (j>0){
			h[i] = s[i];
		}
		else if (j == 0){
			continue;
		}
		else{
			m[i - 3] = s[i];
		}
	}
	
	p_(h, m);
	while (!Z(h, m)){
		p_(h, m);
	}

	cout << h << ":" << m;
}
