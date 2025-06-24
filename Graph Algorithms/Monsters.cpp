#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

int n, m;

// idea is to find earliest time for each cell,
// for any monster to visit it;

// then we do bfs for A , and if reach any boundary,
// and we reach before any monster then it is possible ans;

// Approach:

// Multi-source BFS for monsters to calculate ,
// the earliest time a monster can reach any cell (dist).

// BFS for the player to calculate their time to ,
// reach cells (dist2) and record the path (par array).

// While traversing with the player, 
// if they reach an edge cell before any monster, reconstruct and output the path.



void solve(){
	cin>>n>>m;
	vector<string> v(n);
	for(int i = 0; i<n ; i++){
		cin>>v[i];
	}
	int srcX, srcY;
	queue<pair<int, int>> q;
	vector<vector<int>> dist(n, vector<int>(m, 1e9));
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			if(v[i][j] == 'M'){
				q.push({i, j});
				dist[i][j] = 0;
			}
			if(v[i][j] == 'A'){
				srcX = i, srcY = j;
			}
		}
	}

	if(srcX == n-1 || srcY == m-1 || srcX == 0 || srcY == 0) {
		cout<<"YES\n";
		cout<<0<<"\n";
		return;
	}
		
	vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(auto d : dir){
			int nx = x + d.first, ny = y + d.second;
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == '#') continue;
			if(dist[nx][ny] > 1 + dist[x][y]){
				dist[nx][ny] = 1 + dist[x][y];
				q.push({nx, ny});
			}
		}
	}
	queue<pair<int, int>> q2;
	vector<vector<int>> dist2(n, vector<int>(m, 1e9));
	dist2[srcX][srcY] = 0;
	q2.push({srcX, srcY});
	vector<int> par(n*m+1);
	for(int i = 0 ; i<=n*m ; i++){
		par[i] = i;
	}
	while(!q2.empty()){
		int x = q2.front().first, y = q2.front().second;
		q2.pop();
		int node = x*m + y;
		for(auto d : dir){
			int nx = x + d.first, ny = y + d.second;
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == '#' || v[nx][ny] == 'M') continue;
			int adjNode = nx*m + ny;
			if(dist2[nx][ny] > 1 + dist2[x][y]){
				dist2[nx][ny] = 1 + dist2[x][y];
				par[adjNode] = node;
				if((nx == n-1 || ny == m-1 || nx == 0 || ny == 0) && dist2[nx][ny] < dist[nx][ny]){
					cout<<"YES\n";
					string ans;
					int cur = adjNode;
					while(cur != par[cur]){
						int parent = par[cur];
						int curX = cur / m, curY = cur % m;
						int parX = parent / m, parY = parent % m;
						if(parX + 1 == curX) ans += 'D';
						else if(parY + 1 == curY) ans += 'R';
						else if(parX - 1 == curX) ans += 'U';
						else ans += 'L';
						cur = par[cur];
					}
					reverse(ans.begin(), ans.end());
					cout<<ans.size()<<"\n";
					cout<<ans<<"\n";
					return;
				}
				q2.push({nx, ny});
			}
		}
	}
	cout<<"NO\n";
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