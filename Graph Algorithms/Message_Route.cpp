#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll n, m;

void solve(){
	cin>>n>>m;
	vector<ll> adj[n+1];
	for(int i = 0 ; i<m ; i++){
		ll a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<ll> dist(n+1, 1e9);
	vector<ll> prev(n+1);

	queue<ll> q;
	q.push(1);

	dist[1] = 1;

	while(!q.empty()){
		ll u = q.front();
		q.pop();
		for(auto v: adj[u]){
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				q.push(v);
				prev[v] = u;
			}
		}
	}

	if(dist[n] == 1e9){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}

	cout<<dist[n]<<endl;

	vector<ll> path;
	ll x = n;

	while(x != 1){
		path.push_back(x);
		x = prev[x];
	}

	path.push_back(1);

	reverse(path.begin(), path.end());
	
	for(auto p : path){
		cout<<p<<" ";
	}
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