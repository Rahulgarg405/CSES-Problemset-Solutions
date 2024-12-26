#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

// State => dp[i][j] => True, if we can make sum = j with i coins else false;
// temp[i] represents whether i is present as a sum or not;

void solve(){
	int n;
	cin>>n;
	bitset<100001> temp;
	temp[0] = 1;
	for(int i = 0 ; i<n ; i++){
		int x;
		cin>>x;
		temp |= temp<<x;
	}
	
	vector<int> ans;
	for(int i = 1 ; i<=100000 ; i++){
		if(temp[i]) ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto x : ans) cout<<x<<" ";
}
	

int main(){
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;

}