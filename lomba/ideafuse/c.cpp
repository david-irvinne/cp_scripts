#include<bits/stdc++.h>
using namespace std;

#define int long long

struct edge{
  int to, fuel_cost, time_cost;
  edge(int t, int f, int time){
    to = t;
    fuel_cost = f;
    time_cost = time;
  }
};

int N, M, init_fuel, cap, S, D;
const int MXN = 1005, INF = 1e18;
vector<edge> adj[MXN];

int gas_refill[MXN], time_refill[MXN]; 

pair<int,int> dijkstra(int start, int cur_fuel, int dest){ // return -> time needed (seminimal mungkin), sisa bensin (semaksimal mungkin)
  priority_queue<array<int, 3>> pq; // time so far, bensin_skrg, current node
  vector<bool> vis(MXN, false);
  vector<int> dist(MXN, INF);
  vector<int> dist_bensin(MXN, -INF);
  dist[start] = 0;
  dist_bensin[start] = 0;
  pq.push({0, cur_fuel, start});

  while(pq.size()){
    auto[time_so_far, bensin_skrg, current_node] = pq.top();
    pq.pop();
    if(vis[current_node]) continue; 

    time_so_far *= -1;
    
    if(dist[current_node] >= time_so_far){
      dist[current_node] = time_so_far; // buat min
      // cout << "jarak waktu: " << current_node << ": " << time_so_far << '\n';
      if(dist_bensin[current_node] < bensin_skrg) dist_bensin[current_node] = bensin_skrg; // buat max
    }
    vis[current_node] = 1;

    for(auto e : adj[current_node]){
      for(int tt = 0; tt <= 1000 && bensin_skrg + tt * gas_refill[current_node] <= cap; tt++){
        // cout << "bensin skrg: " << bensin_skrg + tt * gas_refill[current_node] << '\n';
        // isi bensin di sini sebanyak tt kali lalu pergi
        if(bensin_skrg + tt * gas_refill[current_node] - e.fuel_cost >= 0) {
          pq.push({ -( time_so_far + tt * time_refill[current_node] + e.time_cost),  bensin_skrg + tt * gas_refill[current_node] - e.fuel_cost, e.to });
        }
      }
    }
  }
  if(vis[dest]){
    return {dist[dest], dist_bensin[dest]}; 
  }
  return {-1, -1};
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M >> init_fuel >> cap >> S >> D;
  for(int i = 0; i < M; i++){
    int u, v, f, w;
    cin >> u >> v >> f >> w;

    adj[u].push_back(edge(v, f, w));
    adj[v].push_back(edge(u, f, w));
  } 

  for(int i = 1; i <= N; i++){
    cin >> gas_refill[i] >> time_refill[i];
  }

 // S ke D
  auto[time1, bensin1] = dijkstra(S, init_fuel, D);

  if(time1 == -1){
    cout << -1 << '\n';
    return 0;
  }
  cout << time1 << '\n';
  
}


/*
4 4 3 5 1 4
1 2 3 5
2 3 2 5
3 4 5 8
4 1 5 30
2 5
1 2
5 2
4 2

*/
