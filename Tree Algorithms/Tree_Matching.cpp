#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9+7;

// The question wants max no. of matchings
// means max set of edges such that not two edges share a node

// State :
// dp[u][0] = max. matching for subtree rooted at u
// if we are not matching u with any of its children means 
// any edge (u, v) is not used ; 

// dp[u][1] = max matching for subtree rooted at u
// if u is matched with any of its children
// means any of the edge (u, v) is considered in set of edges;


// Transitions :
// Case 1 : dp[u][0] : u is not matched :
	// If u is not matched then for each child v, 
	// we can either include it or not
	// dp[u][0] += max(dp[v][0], dp[v][1]) for each v, where v is children of u;

// Case 2 : dp[u][1] : u is matched :
	// we try to match (include) each edge (u, v) 
	// and take max out of all possibilities
	// dp[u][1] = max over all children v of:
    // [ 1 + dp[v][0] + sum over other children x≠v of max(dp[x][0], dp[x][1]) ]
	// we are adding +1 as edge (u, v) is being added to set of edges
	// and as (u, v) is added we can't match v now as it is added once so we add only dp[v][0]
	// and for rest children we can either include or exclude them so we take max of both possibilities for them;
	// Since dp[u][0] already equals the sum of all max(dp[x][0], dp[x][1]) (including for v),
	// we can just subtract max(dp[v][0], dp[v][1]) — which was v’s contribution —
	// and then add the correct one, dp[v][0].

// Final Answer = max(dp[1][0], dp[1][1]);

const int maxN = 200001;

vector<ll> adj[maxN];
ll dp[maxN][2];
ll n;

void dfs(ll u, ll par){
	dp[u][0] = dp[u][1] = 0;
	for(auto v : adj[u]){
		if(v == par) continue;
		dfs(v, u);
	}

	for(auto v : adj[u]){
		if(v == par) continue;
		dp[u][0] += max(dp[v][0], dp[v][1]);
	}

	for(auto v : adj[u]){
		if(v == par) continue;
		ll otherSum = dp[u][0] - max(dp[v][0], dp[v][1]);
		dp[u][1] = max(dp[u][1], 1 + dp[v][0] + otherSum);
	}
}


void solve(){
	cin>>n;
	for(int i = 0 ; i<n-1 ; i++){
		ll u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout<<max(dp[1][0], dp[1][1])<<endl;
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