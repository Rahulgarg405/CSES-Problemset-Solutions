#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


// State => dp[sum] = min. no. of coins to construct sum;
// Transition : dp[sum] = min(dp[sum-c[j]]) + 1, 0<=j<n;


int main(){
	ll n, x;
	cin>>n>>x;
	vector<int> arr(n+1);
	vector<int> dp(x+1, 0);
	for(int i = 0 ; i<n ; i++){
		cin>>arr[i];
	}
	for(int sum = 1 ; sum <= x; sum++){
		int ans = 1e9;
		for(int i = 0 ; i<n ; i++){
			if(sum-arr[i] >= 0) ans = min(ans, dp[sum-arr[i]]+1);
		}
		dp[sum] = ans;
	}
	if(dp[x] == 1e9) cout<<-1<<"\n";
	else cout<<dp[x]<<"\n";
	return 0;
}