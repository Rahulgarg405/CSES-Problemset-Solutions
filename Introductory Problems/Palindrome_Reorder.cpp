#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	string s;
	cin>>s;
	int n = s.length();
	int hash[26] = {0};
	for(auto c : s) hash[c-'A']++;
	int oddCount = 0;
	for(int i = 0 ; i<26 ; i++){
		if(hash[i]%2 != 0) oddCount++;
	}
	if(oddCount > 1) {
		cout<<"NO SOLUTION\n";
		return;
	}
	
	string ans = s;
	int x = 0, y = n-1;
	for(int i = 0 ; i<n ; i++){
		if(hash[s[i]-'A']%2 == 0){
			while(hash[s[i]-'A'] > 0){
				ans[x] = s[i];
				ans[y] = s[i];
				hash[s[i]-'A'] -= 2;
				x++;y--;
			}
		}
		else{
			ans[n/2] = s[i];
			hash[s[i]-'A']--;
		}
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