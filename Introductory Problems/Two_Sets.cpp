#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll n;
	cin>>n;
	ll sum = (n*(n+1)) / 2;
	if(sum&1ll){
		cout<<"NO\n";
		return;
	}
	ll req = sum/2;
	ll i = 1, j = n;
	ll temp = 0;
	while(temp != req){
		temp += j;
		j--;
		if(temp == req) break;
		temp += i;
		i++;
		if(temp == req) break;
	}
	cout<<"YES\n";
	cout<<j-i+1<<"\n";
	for(int k = i ; k<=j ; k++){
		cout<<k<<" ";
	}
	cout<<"\n";
	cout<<n-(j-i+1)<<"\n";
	for(int k = 1 ; k<i ; k++) cout<<k<<" ";
	for(int k = j+1 ; k<=n ; k++) cout<<k<<" ";
	cout<<endl;
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