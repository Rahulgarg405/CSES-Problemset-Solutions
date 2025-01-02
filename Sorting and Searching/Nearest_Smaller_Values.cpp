#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	stack<int> st;
	for(int i = 0 ; i<n ; i++){
		ll val = v[i];
		while(!st.empty() && v[st.top()] >= val){
			st.pop();
		}
		if(st.empty()) cout<<0<<" ";
		else cout<<st.top()+1<<" ";
		st.push(i);
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