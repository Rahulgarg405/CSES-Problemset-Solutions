#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll n;
	cin>>n;
	vector<vector<ll>> v(n, vector<ll>(3));
	for(int i = 0 ; i<n ; i++){
		cin>>v[i][0]>>v[i][1];
		v[i][2] = i;
	}
	sort(v.begin(), v.end());
	
	ll count = 0;
	vector<ll> ans(n);
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

	for(int i = 0 ; i<n ; i++){
		ll arr = v[i][0] , dep = v[i][1], ind = v[i][2];
		if(pq.empty() || pq.top().first >= arr) {
			count++;
			ans[ind] = count;
			pq.push({dep, count});
		}
		else{
			ll vacantRoomCount = pq.top().second;
			pq.pop();
			pq.push({dep, vacantRoomCount});
			ans[ind] = vacantRoomCount;
		}
	}
	cout<<count<<endl;
	for(auto x: ans) cout<<x<<" ";
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