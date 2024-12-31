#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	int n;
	cin>>n;
	map<int, int> mp;
	ll ans = 0;
	for(int i = 0 ; i<n ; i++){
		int x;
		cin>>x;
		if(mp.find(x-1) == mp.end()) ans++;
		mp[x]++;
	}
	cout<<ans<<endl;
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