#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

bool static comp(pair<int, int> &a, pair<int,int> &b){
	return a.second < b.second;
}

void solve(){
	int n;
	cin>>n;
	vector<pair<int, int>> v(n);
	for(int i = 0 ; i<n ; i++){
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(), v.end(), comp);
	int last = 0, count = 0;
	for(int i = 0 ; i<n ; i++){
		int start = v[i].first, end = v[i].second;
		if(start >= last){
			count++;
			last = end;
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