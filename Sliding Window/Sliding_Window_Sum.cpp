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
	ll sum = 0;
	for(int i = 0 ; i<k ; i++){
		sum += v[i];
	}
	ll ans = sum;
	ll l = 0, r = k;
	while(r < n){
		sum -= v[l++];
		sum += v[r++];
		ans ^= sum;
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