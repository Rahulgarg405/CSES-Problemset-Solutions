#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


ll subarraySumSmallerThan(vector<ll> &v, ll x){
	ll l = 0, r = 0, n = v.size();
	ll sum = 0, count = 0;
	while(r < n){
		sum += v[r];
		while(sum > x){
			sum -= v[l];
			l++;
		}
		count += r-l+1;
		r++;
	}
	return count;
}


// Subarray sum equal to x == subarraySumGreaterThan(x-1) - subarraySumGreaterThan(x);
	// or
// Subarray sum equal to x == subarraySumSmallerThan(x) - subarraySumSmallerThan(x-1); 
 
 
// ll subarraySumGreaterThan(vector<ll> &v, ll x){
// 	ll l = 0, r = 0, n = v.size();
// 	ll sum = 0, count = 0;
// 	while(r < n){
// 		sum += v[r];
// 		while(sum > x){
// 			count += n-r;
// 			sum -= v[l];
// 			l++;
// 		}
// 		r++;
// 	}
// 	return count;
// }

// ll ans = subarraySumGreaterThan(v, x-1) - subarraySumGreaterThan(v, x);


void solve(){
	ll n, x;
	cin>>n>>x;
	vector<ll> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	ll ans = subarraySumSmallerThan(v, x) - subarraySumSmallerThan(v, x-1);
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