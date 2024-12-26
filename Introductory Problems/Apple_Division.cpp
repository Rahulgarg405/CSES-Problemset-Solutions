#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

int n;
int v[101];
ll total = 0;

ll rec(int i, ll sum){
	if(i == n){
		return abs(total - 2*sum);
	}
	ll ans = min(rec(i+1, sum), rec(i+1, sum+v[i]));
	return ans;
}

void solve(){
	cin>>n;
	for(int i =  0 ; i<n ; i++){
		cin>>v[i];
		total += v[i];
	}
	cout<<rec(0, 0)<<endl;
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