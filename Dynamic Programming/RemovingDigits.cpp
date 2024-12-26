#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[x] = min. no. of steps required to make number x equal to 0;


int main(){
	int n;
	cin>>n;
	vector<int> dp(n+1, 1e9);
	dp[0] = 0;
	for(int x = 1 ; x <= n ; x++){
		int temp = x;
		while(temp){
			int digit = temp%10;
			temp = temp/10;
			if(x-digit >= 0 && digit != 0) dp[x] = min(dp[x], 1+dp[x-digit]);
		}
	}
	cout<<dp[n]<<"\n";
	return 0;

}