#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[i] => LIS till ith index;


void solve(){
	int n;	
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i<n ; i++) cin>>v[i];
	vector<int> ans;
	ans.push_back(v[0]);
	for(int i = 1 ; i<n ; i++){
		if(v[i] > ans.back()) ans.push_back(v[i]);
		else{
			int ind = lower_bound(ans.begin(), ans.end(), v[i])-ans.begin();
			ans[ind] = v[i];
		}
	}
	cout<<ans.size()<<"\n";
}
	

int main(){
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;

}