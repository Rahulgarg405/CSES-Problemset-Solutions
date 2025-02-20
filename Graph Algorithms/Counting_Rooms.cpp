#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


ll n, m;

void dfs(int i, int j, vector<string> &v){
	if(i < 0 || j < 0 || i >= n || j >= m || v[i][j] == '#') return;
	v[i][j] = '#';
	dfs(i+1, j, v);
	dfs(i-1, j, v);
	dfs(i, j+1, v);
	dfs(i, j-1, v);
}

void solve(){
	cin>>n>>m;
	vector<string> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	ll count = 0;
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			if(v[i][j] == '.'){
				count++;
				dfs(i, j, v);
			}
		}
	}
	cout<<count<<endl;
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