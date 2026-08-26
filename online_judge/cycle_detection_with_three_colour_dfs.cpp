// https://atcoder.jp/contests/abc456/tasks/abc456_e
// created at: 2026-08-26 21:53:29
#include<bits/stdc++.h>
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

cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}
const int N = 1e5;
vector<int> adj[N + 1];
string s[N+1];
bool vis[N+1][11], hasCycle;
int col[N+1][11];
int w;

void dfs(int cur, int day){
  col[cur][day] = 1;
  int nd = (day + 1) % w;

  auto go = [&](int to) {
    if(!vis[to][nd]) return ;
    if(col[to][nd] == 1) {
      hasCycle = 1;
      return ;
    }
    if(col[to][nd] == 0) dfs(to, nd);
  };

  go(cur);
  for(int nxt : adj[cur]) go(nxt);

  col[cur][day] = 2;
}

void doumo_same_desu(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i <= n; i++){
    adj[i].clear();
    memset(col[i], 0, sizeof(col[i]));
  } 

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cin >> w;
  for(int i = 1; i <= n; i++){
    cin >> s[i];
  }
  
  for(int i = 0; i <= n; i++) for(int j= 0; j <= w; j++) vis[i][j]=false;
  queue<pair<int,int>> q; // loc, day
  for(int i = 1; i <= n; i++){
    if(s[i][0] == 'o')  {
      q.push({i, 0});
      vis[i][0] = 1;
    }
  }
  
  while(q.size()){
    auto[loc, day] = q.front();
    q.pop();

    for(int nxt : adj[loc]) {
      if(day + 1 <= w && s[nxt][(day + 1) % w] == 'o' && !vis[nxt][day + 1]) {
        q.push({nxt, day + 1});
        vis[nxt][(day+1)%w] = 1;
      }
    }
    if(day + 1 <= w && s[loc][(day + 1) % w] == 'o' && !vis[loc][day+1]) {
      q.push({loc, day + 1});
      vis[loc][(day+1)%w] = 1;
    }
  }

  hasCycle = false;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < w; j++) if(col[i][j] == 0) dfs(i, j);
  }
  cout << (hasCycle ? "Yes" : "No") << '\n';
}

/*

3

4 4
1 2
1 4
2 4
2 3
3
xxo
xox
oxo
oxx

1 0
4
oooo

5 5
1 4
2 3
4 5
3 4
2 5
7
oxxxxxx
xxoxxxo
xxxoxox
xoxxoxx
oxxxoxx
*/
