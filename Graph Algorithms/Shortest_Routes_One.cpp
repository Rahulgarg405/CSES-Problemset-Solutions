#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll n, m;

void solve(){
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	for(int i = 0 ; i<m ; i++){
		ll a, b, wt;
		cin>>a>>b>>wt;
		adj[a].push_back({b, wt});
	}

	vector<ll> dist(n+1, 1e18);
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	pq.push({0, 1});
	dist[1] = 0;

	while(!pq.empty()){
		ll node = pq.top().second, wt = pq.top().first;
		pq.pop();
		if (wt > dist[node]) continue;
		for(auto it : adj[node]){
			ll adjNode = it.first, edgeWt = it.second;
			if(dist[adjNode] > wt + edgeWt){
				dist[adjNode] = wt + edgeWt;
				pq.push({dist[adjNode], adjNode});
			}
		}
	}

	for(int i = 1 ; i<=n ; i++){
		cout<<dist[i]<<" ";
	}
	cout<<"\n";
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