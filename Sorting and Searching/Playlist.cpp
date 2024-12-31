#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


// we need to find longest subarray with unique elements;

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	map<int , int> mp;
	ll l = 0, r = 0, ans = 0;
	while(r < n){
		mp[v[r]]++;
		while(mp.size() < r-l+1){
			mp[v[l]]--;
			if(mp[v[l]] == 0) mp.erase(v[l]);
			l++;
		}
		ans = max(ans, r-l+1);
		r++;
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