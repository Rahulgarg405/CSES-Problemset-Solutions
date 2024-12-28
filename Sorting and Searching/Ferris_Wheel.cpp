#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

void solve(){
	int n, x;
	cin>>n>>x;
	vector<ll> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	int i = 0, j = n-1;
	ll count = 0;
	while(i<=j){
		if(v[i] + v[j] <= x){
			i++;j--;
			count++;
		}
		else {
			count++;
			j--;
		}
	}
	cout<<count<<"\n";
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