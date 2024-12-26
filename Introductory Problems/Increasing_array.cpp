#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i<n ; i++) cin>>v[i];
	ll ans = 0;
	for(int i = 1 ; i<n ; i++){
		if(v[i] < v[i-1]) {
			ans += v[i-1]-v[i];
			v[i] = v[i-1];
		}
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