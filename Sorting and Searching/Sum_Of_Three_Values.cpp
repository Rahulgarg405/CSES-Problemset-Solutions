#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll n, x;
	cin>>n>>x;
	vector<ll> v(n);
	vector<pair<ll,ll>> arr(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
		arr[i] = {v[i], i+1};
	}
	sort(arr.begin(), arr.end());
	for(int i = 0 ; i<n ; i++){
		int l = i+1, r = n-1;
		while(l < r){
			ll sum = arr[i].first + arr[l].first + arr[r].first;
			if(sum == x){
				cout<<arr[i].second<<" "<<arr[l].second<<" "<<arr[r].second<<endl;
				return;
			}
			if(sum < x) l++;
			else if(sum > x) r--;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
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