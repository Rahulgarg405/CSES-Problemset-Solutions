#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[i][j] => Edit distance from i, j till last;

int dp[5001][5001];
int n, m;
string a, b;

void solve(){
	cin>>a>>b;
	n = a.length(), m = b.length();
	for(int i = n ; i>=0 ; i--){
		for(int j = m ; j>=0 ; j--){
			if(i == n || j == m) dp[i][j] = (n-i)+(m-j);
			else{
				int ans = 0;
				if(a[i] == b[j]) ans = dp[i+1][j+1];
				else{
					// delete => dp[i][j] = 1+dp[i+1][j];
					// replace => dp[i][j] = 1+dp[i+1][j+1];
					// add => dp[i][j] = 1+dp[i][j+1];
					ans = 1 + min({dp[i+1][j] , dp[i+1][j+1], dp[i][j+1]});
				}
				dp[i][j] = ans;
			}
		}
	}
	cout<<dp[0][0]<<"\n";
}
	

int main(){
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;

}