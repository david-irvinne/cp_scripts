#include<bits/stdc++.h>
#include <queue>
using namespace std;

#define int long long 
#define Int __int128_t
#define pii pair<int,int>

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

const int INF = 1e15, MXN = 1e5 +5;
vector<pair<int,int>> adj[MXN], nity[MXN];
int dist[MXN];

void doumo_same_desu(){
	int N, T, M, K, Q, S, X;
  cin >> N >> T >> M >> K >> Q >> S >> X;

  vector<int> tw(T), en(T); // teleport waypoint, energi nya
  for(int i = 0; i < T; i++){
  	cin >> tw[i] >> en[i];
  }

  for(int i = 0; i < M; i++){
  	int u, v, w; cin >> u >> v >> w;
  	adj[u].push_back({v, w});
  	adj[v].push_back({u, w});
  	nity[u].push_back({v, w});
  	nity[v].push_back({u, w});
  }
  // tambahan teleport waypoint ke nity
  for(int i = 0; i < T; i++){
    for(int j= i + 1; j < T; j++){
      int u = tw[i];
      int v = tw[j];
      int w = abs(en[i] - en[j]);
      nity[u].push_back({v, w});
      nity[v].push_back({u, w});
    }
  }

  vector<int> kota_inf(K);
  for(int i = 0; i < K; i++) cin >> kota_inf[i];

  vector<int> hilang(N + 5, INF);
	for(int i = 0; i < Q; i++){
		int c, d; cin >> c >> d;
		hilang[d] = c; // waktu, nomor kota
	}
	
	vector<int> waktu_virus(N + 5, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for(int kota : kota_inf){
		waktu_virus[kota] = 0;
		pq.push({0, kota});
	}

	// dijkstra utk waktu virus
	while(!pq.empty()){
    auto [cur_t, kota] = pq.top(); pq.pop();
    if(cur_t != waktu_virus[kota]) continue;
   
    // ga bakal nyebar
    if(cur_t >= hilang[kota]) continue; 

    for(auto [v, w]: adj[kota]){
      int sampe = cur_t + w;
      
      // bisainfeksi klo waktu sampe lebih awal dan blm hilang
      if(sampe < waktu_virus[v] && sampe <= hilang[v]){
          waktu_virus[v] = sampe;
          pq.push({sampe, v});
      }
    }
  }

  for(int i = 0; i < MXN; i++) dist[i] = INF;
  dist[S] = 0; 
  pq.push({0, S});

  while(!pq.empty()){
    auto [cur_t, kota] = pq.top(); pq.pop();
    if(cur_t != dist[kota]) continue;
   	
   	// sampe exit
    if(kota== X){
        cout << cur_t << "\n";
        return ;
    }

    for(auto [v, w] : nity[kota]){
      int sampe = cur_t + w;
      // make sure saat ke nxt node blm infected dan blm hilang
      if(sampe < waktu_virus[v] && sampe < hilang[v]){
        if(sampe < dist[v]){
          dist[v] = sampe;
          pq.push({sampe, v});
        }
      }
    }
  }


  cout << -1 << "\n";
}

/*
18 5 16 3 2 1 16
5 1
6 10
11 2
9 9
13 10
1 2 1
1 4 2
2 3 1
2 6 4
4 5 6
5 6 4
7 12 7
8 10 5
9 10 2
10 11 1
11 12 3
13 17 3
13 18 42
14 17 7
15 17 12
16 17 3
3 7 18
6 12
0 18
*/
