// created at: 2026-08-22 18:05:21
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

cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}

int n, m;
vector<int> get_path(int st, int dst, vector<int>&prv) {
  vector<int> res;
  while(dst != st){
    res.push_back(dst);
    dst = prv[dst];
  }
  res.push_back(dst);
  reverse(res.begin(), res.end());
  return res;
}

void doumo_same_desu(){
  cin >> n >> m;
  vector<vector<int>> adj(n + 5);
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> dist(n + 5, LLONG_MAX);
  vector<int> prv(n + 5, -1);
  dist[1] = 0;
  queue<int> q; q.push(1);
  int x = -1, y = -1;
  while(q.size()){
    int now = q.front();
    q.pop();

    for(int nxt : adj[now]){
      if(dist[nxt] == LLONG_MAX){
        dist[nxt] = dist[now] + 1;
        q.push(nxt);
        prv[nxt] = now;
      }
      else if(dist[nxt] == dist[now]){
        x = nxt;
        y = now;
        break;
      }
    }
    if(x != -1) break;
  }
  if(x == -1){
    cout << x << '\n';
    return ;
  }
  // dbg(x);
  // dbg(y);

  vector<int> p1 = get_path(1ll, x, prv), p2 = get_path(1ll, y, prv);
  // for(int j : p1) cout << j << ' ';
  // cout << '\n';
  // for(int j : p2) cout << j << ' ';
  // cout << '\n';
  
  vector<int> res;
  int found = -1;
  for(int i = p1.size() - 1; i >= 0; i--){
    if(p1[i] == p2[i]) {
      found = i;
      break;
    }
  }
  int ii = found;
  while(ii < (int)p1.size()) {
    res.push_back(p1[ii++]);
  }
  ii = p2.size() - 1;
  while(ii > found) {
    res.push_back(p2[ii--]);
  }

  cout << res.size() << '\n';
  for(int i : res) cout << i << ' ';
  cout << '\n';
}

/*

4
3 3
1 2
2 3
1 3

7 7
1 2
2 3
3 4
1 4
4 5
5 6
6 7

5 5
1 2
2 3
3 4
4 5
1 5

9 10
1 2
2 3
3 4
4 5
1 5
6 7
7 8
8 9
6 9
1 6
*/
