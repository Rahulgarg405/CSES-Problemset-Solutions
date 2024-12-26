#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[i][j] = no. of paths to reach to n-1, n-1 from i, j;

int main(){
	int n;
	cin>>n;
	vector<vector<char>> v(n+1, vector<char>(n+1));
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for(int i = 0; i<n ; i++){
		for(int j = 0;  j<n ; j++) cin>>v[i][j];
	}
	for(int i = n-1 ; i>=0; i--){
		for(int j = n-1 ; j>=0; j--){
			if(i == n-1 && j == n-1){
				if(v[i][j] == '.') dp[i][j] = 1;
				else dp[i][j] = 0;
			} 
			else{
				if(v[i][j] == '*') dp[i][j] = 0;
				else dp[i][j] = (dp[i+1][j] + dp[i][j+1])%MOD;
			}
		}
	}
	cout<<dp[0][0];
	return 0;

}