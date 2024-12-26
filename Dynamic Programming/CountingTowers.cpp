#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[i][j] =>
// dp[i][0] => No. of towers if no dash at ith level (dash = horizontal line);
// dp[i][1] => No. of towers if there is dash at ith level;

ll dp[1000001][2];

void solve(){
	for(int i = 1 ; i<=1000000 ; i++){
		if(i == 1){
			dp[i][0] = 1;
			dp[i][1] = 1;
		}
		else{
			dp[i][1] = (4*dp[i-1][1] + dp[i-1][0])%MOD;
			dp[i][0] = (2*dp[i-1][0] + dp[i-1][1])%MOD;
		}
	}
}

int main(){
	int t;
	cin>>t;
	solve();
	while(t--){
		int n;
		cin>>n;
		cout<<(dp[n][1] + dp[n][0])%MOD<<"\n";
	}
	return 0;

}