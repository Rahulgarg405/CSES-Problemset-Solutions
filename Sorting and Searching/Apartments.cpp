#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

void solve(){
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> a(n), b(m);
	for(int i = 0 ; i<n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i<m ; i++){
		cin>>b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll i = 0, j = 0, count = 0;
	while(i<n && j<m){
		int mini = a[i]-k, maxi = a[i]+k;
		if(b[j] < mini) j++;
		else if(b[j] > maxi) i++;
		else{
			count++;i++;j++;
		}
	}
	cout<<count<<"\n";
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