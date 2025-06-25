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
	set<pair<ll,ll>> st;
	map<ll,ll> mp;
	for(int i = 0 ; i<k ; i++){
		if(mp.find(v[i]) == mp.end()){
			mp[v[i]]++;
			st.insert({-mp[v[i]], v[i]});
		}
		else{
			ll prevF = mp[v[i]];
			mp[v[i]]++;
			st.erase({-prevF, v[i]});
			st.insert({-mp[v[i]], v[i]});
		}
	}
	cout<<st.begin()->second<<" ";
	ll l = 0, r = k;
	while(r < n){
		ll prevF = mp[v[l]];
		mp[v[l]]--;
		st.erase({-prevF, v[l]});
		if(mp[v[l]] == 0) mp.erase(v[l]);
		else st.insert({-mp[v[l]], v[l]});

		if(mp.find(v[r]) == mp.end()){
			mp[v[r]]++;
			st.insert({-mp[v[r]], v[r]});
		}
		else{
			ll prevF = mp[v[r]];
			mp[v[r]]++;
			st.erase({-prevF, v[r]});
			st.insert({-mp[v[r]], v[r]});
		}

		l++;r++;
		cout<<st.begin()->second<<" ";
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