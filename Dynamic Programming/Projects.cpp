#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
const int MOD = 1e9+7;
const ll INF = 1000000000;

// State => dp[i] => Max. Money we can earn from i till last;


void solve(){
	int n;	
	cin>>n;
	vector<pair<ll, pair<ll, ll>>> v(n);
	for(int i = 0 ; i<n ; i++){
		ll l, r, p;
		cin>>l>>r>>p;
		v[i] = MP(l, MP(r, p));
	}
	// we sort it according to start time :
	//  so intervals :

	// [........]
	// 		[..........]
	// 				[..............]

	// then if we take some project , we find next interval which is greater then it
	// as we can only take project which starts after current one ends, else we cant take it
	// so it discards between elements
	// as it is sorted we use upper bound for it

	sort(v.begin(), v.end());
	vector<ll> dp(n+1);
	for(int i = n ; i>=0 ; i--){
		if(i == n) dp[i] = 0;
		else{
			// don't take :
			dp[i] = dp[i+1];
			// take :
			ll nextVal = v[i].second.first;
			auto it = upper_bound(v.begin(), v.end(), MP(nextVal, MP(INF, INF)))-v.begin();
			dp[i] = max(dp[i], v[i].second.second+dp[it]);
		}
	}
	cout<<dp[0]<<"\n";
}
	

int main(){
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;

}