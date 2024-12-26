#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


// State => dp[i] = no. of ways to construct n from i;

int main(){
	ll n;
	cin>>n;
	vector<int> dp(n+10, 0);
	for(int i = n ; i>=0 ; i--){
		if(i == n) dp[i] = 1;
		else {
			for(int j = 1 ; j<=6 ; j++){
				dp[i] = (dp[i] + dp[i+j])%MOD;
			}
		}
	}
	cout<<dp[0]<<"\n";
	return 0;
}