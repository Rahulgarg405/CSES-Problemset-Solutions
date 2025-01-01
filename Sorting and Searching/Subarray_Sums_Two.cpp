#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


// we maintain a prefix sum and,
// if it is equal to x , we found 1 possible subaray,
// we check if prefixSum - x , is there in hash table that we hashed till now,
// if it exists, that means,
// there is a subarray sum which we can remove from current subarray to make x,
// => prefixSum + y = x;(so we need y prefixSum of any subarray to be removed from current prefixSum to make it equal to x);
// so we add no. of occurences of it to ans;


//  we need to remove this 			to get this portion
// [......................sum = k][..................sum == x]
// <---------------------prefixSum--------------------------->
// so we need to remove k = prefixSum-x from it to be valid;



void solve(){
	ll n, x;
	cin>>n>>x;
	vector<ll> v(n);
	map<ll, ll> mp;
	ll ans = 0, prefixSum = 0;
	for(int i = 0 ; i<n ; i++){
		ll val;
		cin>>val;
		prefixSum += val;
		if(prefixSum == x) ans++;
		if(mp.find(prefixSum-x) != mp.end()){
			ans += mp[prefixSum-x];
		}
		mp[prefixSum]++;
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