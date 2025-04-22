#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// dp[i][prev][isStarted][tight] :
// => no. of valid numbers from i till no. of digits in number
// where previous digit is prev, 
// and isStarted indicates whether number is started means 
// if there are leading zeroes => no started, else started
// and tight tells whether we are in tight constraint or not;

ll dp[20][11][2][2];

ll rec(string &s, int i, int prev, int isStarted, int tight){
	if(i == s.size()) return 1;
	if(dp[i][prev+1][isStarted][tight] != -1) return dp[i][prev+1][isStarted][tight];
	ll ans = 0;
	int upperBound = (tight ? s[i]-'0' : 9);

	for(int digit = 0 ; digit <= upperBound ; digit++){
		if(isStarted && digit == prev)
        	continue;
        
        ans += rec(s, i + 1, digit, (isStarted | (digit!=0)), (tight & (digit == upperBound)));
	}
	return dp[i][prev+1][isStarted][tight] = ans;
}

void solve(){
	ll l, r;
	cin>>l>>r;
	ll ans = 0;
	if(l == 0) ans++;
	if(l > 0) l--;
	string left = to_string(l);
	string right = to_string(r);
	memset(dp, -1, sizeof(dp));
	ll countR = rec(right, 0, -1, 0, 1);
	memset(dp, -1, sizeof(dp));
	ll countL = rec(left, 0, -1, 0, 1);
	ans += countR-countL;
	cout<<ans<<endl;
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