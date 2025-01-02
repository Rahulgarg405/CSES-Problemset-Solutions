#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll n, k;
// check returns true,
// if k no. of subarrays can be made having max sum as x;
bool check(ll x, vector<ll> &v){
	ll sum = 0, count = 1;
	for(int i = 0 ; i<n ; i++){
		if(sum+v[i] > x) {
			if(v[i] > x) return 0;
			sum = v[i];
			count++;
		}
		else sum += v[i];
	}
	return count <= k;
}

void solve(){
	cin>>n>>k;
	vector<ll> v(n);
	ll sum = 0;
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
		sum += v[i];
	}
	
	ll lo = 0, hi = sum, ans = 0;
	while(lo <= hi){
		ll mid = lo+(hi-lo)/2;
		if(check(mid, v)){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
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