#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


int main(){
	ll n;
	cin>>n;
	vector<int> v(n);
	ll sum = 0;
	for(int i = 0; i<n-1 ; i++) {
		cin>>v[i];
		sum += v[i];
	}
	ll ogSum = (n*(n+1))/2;
	ll ans = ogSum-sum;
	cout<<ans<<endl;
	return 0;
}