// created at: 2026-08-22 19:21:32
#include<bits/stdc++.h>
#include <climits>
using namespace std;

#define int long long 
#define Int __int128_t

#ifdef DEBUG
#define dbg(x) cout << "["<< #x <<"] : "<< (x) <<endl;
#else
#define dbg(x)
#endif

int bpow(int a, int b, int64_t mod = LLONG_MAX) {
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

//	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}

vector<int> v = {0, 1, 0, -1};
vector<int> h = {1, 0, -1, 0};

void doumo_same_desu(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<string>s(n);
  vector<bool> badrow(n), badcol(m);
  for(int i = 0; i < n; i++){
    cin >> s[i];

    for(int j = 0; j < m; j++){
      if(s[i][j] == '#'){
        badrow[i] = 1;
        badcol[j] = 1;
      }
    }
  }
  
  queue<pair<int,int>> q;
  vector<vector<int>> dist(n, vector<int>(m, LLONG_MAX));
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!badrow[i] && !badcol[j]){
        q.push({i, j});
        dist[i][j] = 0;
      } 
    }
  }
  dbg(q.size());
  // while(q.size()){
  //   auto [x, y] = q.front();
  //   cout << x << ' ' << y << '\n';
  //   q.pop();
  // }
  

  while(q.size()){
    auto[x, y] = q.front();
    q.pop();
    if(vis[x][y]){
      continue;
    }
    vis[x][y] = 1;
  
    for(int kk = 0; kk < 4; kk++){
      int nx = x + v[kk], ny = y + h[kk];
      if(0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] == '.') {
        dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);
        q.push({nx, ny});
      }
    }
  }

  int res = 0;
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) res += dist[i][j] <= k;
  cout << res << '\n';

}

/*

*/
