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
	
	map<ll, ll> mp;
	ll l = 0, r = 0, count = 0, distinct = 0;
	while(r < n){
		if(mp.find(v[r]) == mp.end()) distinct++;
		mp[v[r]]++;
		while(distinct > k){
			mp[v[l]]--;
			if(mp[v[l]] == 0){
				mp.erase(v[l]);
				distinct--;
			}
			l++;
		}
		count += r-l+1;
		r++;
	}
	cout<<count<<endl;
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