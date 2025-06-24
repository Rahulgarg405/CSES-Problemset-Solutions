#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll n, k;
	cin>>n>>k;
	ll x, a, b, c;
	cin>>x>>a>>b>>c;
	vector<ll> v(n);
	v[0] = x;
	for(int i = 1 ; i<n ; i++){
		v[i] = (a*v[i-1] + b)%c;
	}
	ll xorr = 0;
	for(int i = 0 ; i<k ; i++){
		xorr ^= v[i];
	}
	ll ans = xorr;
	ll l = 0, r = k;
	while(r < n){
		xorr ^= v[l++];
		xorr ^= v[r++];
		ans ^= xorr;
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