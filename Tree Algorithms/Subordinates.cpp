#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9+7;

int dfs(int i, vector<vector<int>> &adj, vector<int> &ans, int n){
	int sub = 0;
	for(auto child : adj[i]){
		sub += 1 + dfs(child, adj, ans, n);
	}
	ans[i] = sub;
	return sub;
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> adj(n+1);
	for(int i = 2 ; i<=n ; i++){
		int boss;
		cin>>boss;
		adj[boss].push_back(i);
	}
	vector<int> ans(n+1, 0);
	dfs(1, adj, ans, n);
	for(int i = 1 ; i<=n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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