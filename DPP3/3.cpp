#include<bits/stdc++.h>

using namespace std;

void printAnagram(vector<string> &a) {
	map<map<char,int>,vector<string>> mp1;
	for(int i=0;i<a.size();i++) {
		map<char,int> mp2;
		vector<string> temp;
		for(int j=0;j<a[i].size();j++) {
			mp2[a[i][j]]++;
		}

		auto it=mp1.find(mp2);
		if(it!=mp1.end()) {
			(it->second).push_back(a[i]);
		}
		else {
			temp.push_back(a[i]);
			mp1.insert({mp2,temp});
		}
	}
	vector<vector<string>> ans;
	for(auto i=mp1.begin();i!=mp1.end();i++) {
		ans.push_back(i->second);
	}

	for(int i=0;i<ans.size();i++) {
		for(int j=0;j<ans[i].size();j++) {
			cout<<ans[i][j]<<" ";
		}
	}
}

int main() {
	int n;
	cin>>n;
	vector<string> a(n);
	for(auto &i:a)
		cin>>i;
	printAnagram(a);
	return 0;
}