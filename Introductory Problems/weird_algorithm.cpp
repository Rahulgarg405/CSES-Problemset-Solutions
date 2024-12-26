#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


int main(){
	ll n;
	cin>>n;
	cout<<n<<" ";
	while(n != 1){
		if(n&1ll) n = n*3+1;
		else n = n/2;
		cout<<n<<" ";
	}
	return 0;
}