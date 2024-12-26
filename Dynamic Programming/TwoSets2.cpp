#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[i][sum] = no. of ways to make sum = required_sum from i till n-1 from sum;

ll n;
ll reqSum;

void solve(){	
	cin>>n;
	ll sum = (n*(n+1))/2;
	if(sum%2 != 0) {
		cout<<0<<endl;
		return;
	}
	reqSum = sum/2;
	vector<vector<ll>> dp(n+2, vector<ll>(reqSum+1, 0));

	for(int i = n ; i>=0; i--){
		for(int j = reqSum ; j >= 0 ; j--){
			if(i == n){
				if(j == reqSum) dp[i][j] = 1;
			}
			else{
				dp[i][j] = dp[i+1][j];
				if(j+i <= reqSum) dp[i][j] = (dp[i][j] + dp[i+1][j+i])%MOD;
			}
		}
	}
	cout<<dp[1][0]<<"\n";
}
	

int main(){
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;

}