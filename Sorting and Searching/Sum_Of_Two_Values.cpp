#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	int n, x;
	cin>>n>>x;
	vector<int> v(n);
	map<int, int> mp;
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
		mp[v[i]] = i;
	}
	for(int i = 0 ; i<n ; i++){
		int req = x-v[i];
		if(req <= 0) continue;
		if(mp.find(req) != mp.end() && mp[req] != i){
			cout<<i+1<<" "<<mp[req]+1<<endl;
			return;
		}
	}
	cout<<"IMPOSSIBLE\n";
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