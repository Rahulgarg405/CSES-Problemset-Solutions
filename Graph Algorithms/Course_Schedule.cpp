#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

int n, m;


void solve(){
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	vector<int> indegree(n+1, 0);
	for(int i = 0 ; i<m ; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		indegree[b]++;
	}
	queue<int> q;
	for(int i = 1 ; i<=n ; i++){
		if(indegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> ans;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto it : adj[node]){
			indegree[it]--;
			if(indegree[it] == 0) q.push(it);
		}
	}
	if(ans.size() != n) {
		cout<<"IMPOSSIBLE\n";
		return;
	}
	for(auto x : ans){
		cout<<x<<" ";
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