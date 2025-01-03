#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll n;
	cin>>n;
	ll maxi = -1e9;
	ll sum = 0;
	for(int i = 0 ; i<n ; i++){
		ll x;
		cin>>x;
		sum += x;
		maxi = max(maxi, x);
	}
	if(maxi > sum-maxi) cout<<2*maxi<<"\n";
	else cout<<sum<<"\n";
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