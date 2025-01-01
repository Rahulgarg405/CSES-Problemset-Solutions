#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll x, n;
	cin>>x>>n;
	multiset<ll> ms;
	set<ll> st;
	st.insert(0);
	st.insert(x);
	ms.insert(x);
	for(int i = 0 ; i<n ; i++){
		ll a;
		cin>>a;
		auto hi = st.lower_bound(a);
		auto lo = hi;
		lo--;
		ms.erase(ms.find(*hi-*lo));
		ms.insert(a-*lo);
		ms.insert(*hi-a);
		st.insert(a);
		auto last = ms.end();
		last--;
		ll highest = *last;
		cout<<highest<<" ";
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