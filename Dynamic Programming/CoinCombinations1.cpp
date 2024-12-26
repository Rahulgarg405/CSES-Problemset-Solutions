#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
 
 
// State => dp[sum] = no. of ways to construct sum;
// Transition : dp[sum] += dp[sum-c[j]], 0<=j<n;
 
 
int main(){
	ll n, x;
	cin>>n>>x;
	vector<int> arr(n+1);
	vector<int> dp(x+1, 0);
	for(int i = 0 ; i<n ; i++){
		cin>>arr[i];
	}
	dp[0] = 1;
	for(int sum = 1 ; sum <= x; sum++){
		ll ans = 0;
		for(int i = 0 ; i<n ; i++){
			if(sum-arr[i] >= 0) ans += dp[sum-arr[i]];
		}
		ans = ans%MOD;
		dp[sum] = ans;
	}
	if(dp[x] == 1e9) cout<<-1<<"\n";
	else cout<<dp[x]<<"\n";
	return 0;

}