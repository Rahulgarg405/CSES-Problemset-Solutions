#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll n, m;

// We have to make a graph and check if,
// it is Bipartite or not;

bool dfs(int i, int color, vector<ll> adj[], vector<int> &vis, vector<int> &c){
	vis[i] = 1;
	c[i] = color;
	bool ans = true;
	for(auto it : adj[i]){
		if(!vis[it]){
			ans &= dfs(it, (color == 0 ? 1 : 0), adj, vis, c);
		}
		else {
			if(c[it] == color) return false;
		}
	}
	return ans;
}

void solve(){
	cin>>n>>m;
	vector<ll> adj[n+1];
	for(int i = 0 ; i<m ; i++){
		ll a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> vis(n+1, 0), c(n+1);
	for(int i = 1 ; i<=n ; i++){
		if(!vis[i]){
			if(!dfs(i, 0, adj, vis, c)){
				cout<<"IMPOSSIBLE\n";
				return;
			}
		}
	}
	for(int i = 1 ; i<=n ; i++){
		cout<<c[i]+1<<" ";
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