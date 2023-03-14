#include<bits/stdc++.h>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+k)%i;
	}
	cout<<ans+1<<endl;
	return 0;
}