#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[i][k] = No. of prefixes of length i with last element k;

// dp[i][k] = dp[i-1][k-1]+dp[i-1][k]+dp[i-1][k+1];


int main(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	vector<int> v(n);
	for(int i = 0; i<n ; i++){
		cin>>v[i];
	}

	// Base Case:
	for(int k = 1 ; k<=m ; k++){
		if(v[0] == 0 || v[0] == k) dp[1][k] = 1;
	}


	for(int i = 2 ; i<= n ; i++){
		for(int k = 1 ;k<=m ; k++){
			if(v[i-1] != 0 && v[i-1] != k){
				dp[i][k] = 0;
				continue;
  			}
  			for(int prev = k-1 ; prev <= k+1 ; prev++){
				if(prev < 1 || prev > m) continue;
				dp[i][k] = (dp[i][k] + dp[i-1][prev])%MOD;
			}
		}
	}

	int ans = 0;
	for(int i = 1 ; i<=m; i++){
		ans = (ans+dp[n][i])%MOD;
	}
	cout<<ans<<endl;
	return 0;

}