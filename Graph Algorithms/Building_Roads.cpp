#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll n, m;
int vis[100010] = {0};

void bfs(ll i, vector<ll> adj[]){
	queue<ll> q;
	q.push(i);
	vis[i] = 1;
	while(!q.empty()){
		ll node = q.front();
		q.pop();
		for(auto it: adj[node]){
			if(!vis[it]){
				vis[it] = 1;
				q.push(it);
			}
		}
	}
}

// approach is to count connected components
// and connect starting point of components;

void solve(){
	cin>>n>>m;
	vector<ll> adj[n+1];
	for(int i = 0 ; i<m ; i++){
		ll a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll count = 0;
	vector<ll> v;
	for(int i = 1 ; i<=n ; i++){
		if(!vis[i]){
			count++;
			bfs(i, adj);
			v.push_back(i);
		}
	}
	cout<<count-1<<endl;
	for(int i = 0 ; i<v.size()-1 ; i++){
		cout<<v[i]<<" "<<v[i+1]<<endl;
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