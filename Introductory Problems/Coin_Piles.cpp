#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


void solve(){
	int a, b;
	cin>>a>>b;
	// x*1 + y*2 = a and
	// y*1 + x*2 = b;
	double x = (double)(2*a - b) / 3;
	double y = (double)(2*b - a) / 3;
	if(((2*a - b + 2) / 3) == x && ((2*b - a + 2) / 3) == y) cout<<"YES\n";
	else cout<<"NO\n";
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