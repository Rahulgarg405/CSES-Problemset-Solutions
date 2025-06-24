#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

int n, m, q;


void solve(){
	cin>>n>>m>>q;
	ll dp[n+1][n+1];
	for(int i = 1 ; i<=n ; i++){
		for(int j = 1 ; j<=n ; j++){
			if(i != j) dp[i][j] = 1e18;
			else dp[i][j] = 0;
		}
	}
	for(int i = 0 ; i<m ; i++){
		ll a, b, c;
		cin>>a>>b>>c;
		dp[a][b] = min(dp[a][b], c);
		dp[b][a] = min(dp[b][a], c);
	}
	for(int k = 1 ; k<=n ; k++){
		for(int i = 1 ; i<=n ; i++){
			for(int j = 1 ; j<=n ; j++){
				if(dp[i][k] != 1e18 && dp[k][j] != 1e18)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 0 ; i<q ; i++){
		int a, b;
		cin>>a>>b;
		ll ans = (dp[a][b] == 1e18 ? -1 : dp[a][b]);
		cout<<ans<<"\n";
	}
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