#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	string s;
	cin>>s;
	int n = s.length();
	int ans = 1, diff = 1;
	for(int i = 1 ; i<n; i++){
		if(s[i] == s[i-1]) diff++;
		else diff = 1;
		ans = max(ans, diff);
	}
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