#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
 
// State => dp[i][k] = no. of ways to construct sum k from i to n-1,such that,
// coins from i ton n are pickable;
// Trnasition => dp[i][k] = dp[i][k-c[i]] + dp[i+1][k];
						//	  pick coin	  	  skip coin  
int main(){
	int n, x;
	cin>>n>>x;
	vector<int> arr(n+1);
	vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
	for(int i = 0 ; i<n ; i++){
		cin>>arr[i];
	}
	for(int i = n ; i>=0 ; i--){
		for(int k = 0 ; k<=x ; k++){
			if(i == n){
				if(k == 0) dp[i][k] = 1;
				else dp[i][k] = 0;
			}
			else{
				dp[i][k] = dp[i+1][k];
				if(k-arr[i] >= 0) dp[i][k] = (dp[i][k] + dp[i][k-arr[i]])%MOD;
			}
		}
	}
	cout<<dp[0][x]<<"\n";
	return 0;

}