#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll n;
	cin>>n;
	vector<pair<ll, ll>> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(), v.end());
	ll ans = 0, duration = 0;
	for(int i = 0 ; i<n ; i++){
		duration += v[i].first;
		ans += v[i].second - duration;
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