#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	int n;
	cin>>n;
	for(ll i = 1 ; i<=n ; i++){
		ll total = i*i * (i*i-1) / 2;
		ll attackWays = 4*(i-1)*(i-2);
		cout<<total - attackWays << endl;
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