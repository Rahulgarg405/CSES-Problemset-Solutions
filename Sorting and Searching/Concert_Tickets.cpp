#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

void solve(){
	int n, m;
	cin>>n>>m;
	map<int, int> mp;
	for(int i = 0 ; i<n ; i++){
		int x;
		cin>>x;
		mp[x]++;
	}
	for(int i = 0 ; i<m ; i++){
		int q;
		cin>>q;
		auto it = mp.upper_bound(q);
		if(it != mp.begin()) {
			it--;
			cout<<it->first<<"\n";
			it->second--;
			if(it->second == 0) mp.erase(it);
		}
		else cout<<-1<<"\n";
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