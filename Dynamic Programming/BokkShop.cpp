#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[i][j] = max. no. of pages we can buy from i till n-1 in j money;


int main(){
	int n, x;
	cin>>n>>x;
	vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
	vector<int> h(n), s(n);
	for(int i = 0; i<n ; i++){
		cin>>h[i];
	}
	for(int i = 0; i<n ; i++){
		cin>>s[i];
	}
	for(int i = n-1 ; i>=0; i--){
		for(int j = 0 ; j<=x ; j++){
			int ans = dp[i+1][j];
			if(j-h[i] >= 0) ans = max(ans, dp[i+1][j-h[i]] + s[i]);
			dp[i][j] = ans;
		}
	}
	cout<<dp[0][x]<<endl;
	return 0;

}