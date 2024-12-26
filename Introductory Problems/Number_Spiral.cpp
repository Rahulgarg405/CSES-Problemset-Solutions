#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	ll y, x;
	cin>>y>>x;
	if(y > x){
		ll total = (y-1)*(y-1);
		ll add = 0;
		if(y%2 == 0){
			add = (2*y)-x;
		}
		else add = x;
		cout<<total+add<<endl;
	}
	else{
		ll total = (x-1)*(x-1);
		ll add = 0;
		if(x%2 == 0){
			add = y;
		}
		else add = (2*x)-y;
		cout<<total+add<<endl;
	}
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