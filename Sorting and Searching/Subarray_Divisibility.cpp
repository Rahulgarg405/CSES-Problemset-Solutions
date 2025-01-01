#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// same concept as of subarray sum equal to k,
// in this we need to find that if , 
// prefixSum % n , has occured or not ,
// so that we can remove that from our current subarray,
// to make it divisible by n;

//  we need to remove this 		to get this portion
// [......................sum%n][...............sum%n == 0]
// <---------------------prefixSum%n------------------>

void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	map<ll, ll> mp;
	ll count = 0, prefixSum = 0;
	for(int i = 0 ; i<n ; i++){
		ll val;
		cin>>val;
		prefixSum += val;
		ll mod = prefixSum%n;
		if(mod < 0) mod += n;
		if(mod == 0) count++;
		if(mp.find(mod) != mp.end()){
			count += mp[mod];
		}
		mp[mod]++;
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