#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

map<string , int> mp;


void solve(){
	string s;
	cin>>s;
	sort(s.begin(), s.end());
	do{
		mp[s]++;
	}while(next_permutation(s.begin(), s.end()));
	cout<<mp.size()<<endl;
	for(auto it : mp) {
		cout<<it.first<<endl;
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}