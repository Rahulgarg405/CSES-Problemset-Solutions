#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
const int MOD = 1e9+7;


void solve(){
	int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i];
	}
	ordered_set<pair<int, int>> window;
	for(int i = 0 ; i<k ; i++){
		window.insert({v[i], i});
	}
	cout<<window.find_by_order((k-1)/2)->first<<" ";
	int l = 0, r = k;
	while(l < n-k){
		window.erase({v[l], l});
		window.insert({v[r], r});
		cout<<window.find_by_order((k-1)/2)->first<<" ";
		l++;
		r++;
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