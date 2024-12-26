#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


ll power(ll a, ll b){
	if(b == 0) return 1;
	ll res = power(a, b/2);
	if(b%2 == 0) return (res*res)%MOD;
	else return ((res*res)%MOD)*a%MOD;
}

void solve(){
	ll n;
	cin>>n;
	cout<<power(2, n)<<endl;
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