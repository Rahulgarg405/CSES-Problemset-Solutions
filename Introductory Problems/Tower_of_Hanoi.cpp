#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

vector<pair<int, int>> ans;

void rec(int n, int start, int end, int mid){
	if(n == 0) {
		return;
	}
	rec(n-1, start, mid, end);
	ans.push_back({start, end});
	rec(n-1, mid, end, start);
}

void solve(){
	int n;
	cin>>n;
	rec(n, 1, 3, 2);
	cout<<ans.size()<<endl;
	for(auto it : ans){
		cout<<it.first<<" "<<it.second<<endl;
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