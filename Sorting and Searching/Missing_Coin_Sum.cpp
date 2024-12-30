#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	for(int i = 0 ; i<n ; i++){
		if(v[i] > sum + 1) break;
		sum += v[i];
	}
	cout<<sum+1<<endl;
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