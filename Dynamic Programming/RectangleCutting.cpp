#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[x][y] => Min. no. of cuts to make rectangle of (x, y) a square;
// Transitions => We make every possible cut in x and y direction and take min of them


int dp[501][501];
int n, m;

void solve(){
	cin>>n>>m;
	for(int x = 1 ; x <= n ; x++){
		for(int y = 1 ; y<=m ; y++){
			if(x==y) dp[x][y] = 0;
			else{
				dp[x][y] = 1e9;
				for(int a = 1 ; a <= x-1 ; a++){
					dp[x][y] = min(dp[x][y], dp[a][y]+dp[x-a][y]+1);
				}
				for(int b = 1 ; b <= y-1 ; b++){
					dp[x][y] = min(dp[x][y], dp[x][b]+dp[x][y-b]+1);
				}
			}
		}
	}
	cout<<dp[n][m]<<"\n";
}
	

int main(){
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;

}