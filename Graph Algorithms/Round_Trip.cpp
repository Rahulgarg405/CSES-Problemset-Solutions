#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll n, m;
vector<int> par, ans;

bool dfs(int i, int parent, vector<vector<int>> &adj, vector<int> &vis){
	vis[i] = 1;
	for(auto it : adj[i]){
		if(!vis[it]){
			par[it] = i;
			if(dfs(it, i, adj, vis)) return true;
		}
		else if(it != parent) {
			ans.push_back(it);
			int cur = i;
			while(cur != it){
				ans.push_back(cur);
				cur = par[cur];
			}
			ans.push_back(it);
			reverse(ans.begin(), ans.end());
			return true;
		}
	}
	return false;
}

void solve(){
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	par.resize(n+1);
	for(int i = 0 ; i<m ; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> vis(n+1, 0);
	for(int i = 0 ; i<n ; i++){
		if(!vis[i]){
			if(dfs(i, -1, adj, vis)){
				cout<<ans.size()<<endl;
				for(auto x : ans){
					cout<<x<<" ";
				}
				cout<<"\n";
				return;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
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