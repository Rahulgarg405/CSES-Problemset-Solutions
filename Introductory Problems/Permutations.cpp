#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	int n;
	cin>>n;
	if(n == 2 || n == 3){
		cout<<"NO SOLUTION\n";
		return;
	}
	int x = n, y = n-1;
	for(int i = y ; i>=1 ; i-=2){
		cout<<i<<" ";
	}
	for(int i = x ; i >= 1 ; i-=2){
		cout<<i<<" ";
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