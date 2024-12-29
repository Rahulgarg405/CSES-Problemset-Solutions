#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n), dep(n);
	for(int i = 0 ; i<n ; i++){
		cin>>arr[i]>>dep[i];
	}
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
	int i = 0, j = 0, ans = 1, count = 0;
	while(i < n && j < n){
		// count holds no. of current customers in shop;
		// arr[i] < dep[j] => means i arrived before j leaves so count++;
		// else => means j will leave shop before i arrives so count--;
		if(arr[i] < dep[j]){
			count++;
			i++;
		}
		else{
			count--;
			j++;
		}
		ans = max(ans, count);
	}
	cout<<ans<<endl;
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