#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll n, k;
	cin>>n>>k;
	vector<ll> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	map<ll,ll> mp;
	for(int i = 0 ; i<k ; i++){
		mp[v[i]]++;
	}
	cout<<mp.size()<<" ";
	ll l = 0, r = k;
	while(r < n){
		mp[v[l]]--;
		if(mp[v[l]] == 0) mp.erase(v[l]);
		mp[v[r]]++;
		l++;r++;
		cout<<mp.size()<<" ";
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