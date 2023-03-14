#include<bits/stdc++.h>

using namespace std;

void towerOfHanoi(int n, char f, char t, char x) {
	if(n==1) {
		cout<<"Move disk from "<<f<<" to "<<t<<endl;
		return;
	}
	towerOfHanoi(n-1,f,x,t);
	cout<<"Move disk from "<<f<<" to "<<t<<endl;
	towerOfHanoi(n-1,x,t,f);
}

int main() {
	int n;
	cin>>n;
	towerOfHanoi(n,'a','c','b');
	return 0;
}