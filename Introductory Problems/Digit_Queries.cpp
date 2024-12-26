#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll k;
	cin>>k;
	ll digit = 1, end = 9, start = 1;
	while(k > end * digit){
		k -= end*digit;
		digit++;
		end *= 10;
		start *= 10;
	}
	ll num = start + (k-1)/digit;
	string ans = to_string(num);
	cout<<ans[(k-1)%digit]<<endl;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}