#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll n, t;

bool check(ll x, vector<ll> &v){
	ll count = 0;
	for(int i = 0 ; i<n ; i++){
		count += x/v[i];
		if(count >= t) return 1;
	}
	return 0;
}


void solve(){
	cin>>n>>t;
	vector<ll> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	ll lo = 0, hi = v[0]*t, ans = 0;
	while(lo <= hi){
		ll mid = lo+(hi-lo)/2;
		if(check(mid, v)){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}
	cout<<ans<<"\n";
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