#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200005;

vector<pair<int, int>> adj[MAXN];
int a[MAXN], b[MAXN];
int N, S1, S2;

void bfs(int start, int dist[]) {
    fill(dist, dist + N + 1, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

ll compute_sum_min(int arr[]) {
    vector<int> sorted(arr + 1, arr + N + 1);
    sort(sorted.begin(), sorted.end());
    ll sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += (ll)sorted[i] * (N - 1 - i);
    }
    return sum;
}

struct Fenwick {
    vector<ll> bit;
    int n;
    
    Fenwick(int n) : n(n), bit(n + 2, 0) {}
    
    void update(int idx, ll delta) {
        for (int i = idx; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }
    
    ll query(int idx) {
        ll res = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }
};

ll compute_sum_min_ab() {
    vector<pair<int, int>> nodes;
    for (int i = 1; i <= N; i++) {
        nodes.push_back({a[i], b[i]});
    }
    
    // Urutkan berdasarkan a_i
    sort(nodes.begin(), nodes.end());
    
    // Compress b values
    vector<int> b_vals;
    for (int i = 0; i < N; i++) {
        b_vals.push_back(nodes[i].second);
    }
    sort(b_vals.begin(), b_vals.end());
    b_vals.erase(unique(b_vals.begin(), b_vals.end()), b_vals.end());
    int m = b_vals.size();
    
    Fenwick cnt_bit(m), sum_bit(m);
    ll total = 0;
    
    for (int i = 0; i < N; i++) {
        int a_val = nodes[i].first;
        int b_val = nodes[i].second;
        
        int b_idx = lower_bound(b_vals.begin(), b_vals.end(), b_val) - b_vals.begin() + 1;
        
        // Untuk semua node v sebelumnya (a_v <= a_u):
        // min(a_u,a_v,b_u,b_v) = min(a_v, min(b_u,b_v))
        
        // Kita bagi menjadi 2 kasus:
        // 1. b_v <= b_u: min = min(a_v, b_v)
        // 2. b_v > b_u: min = min(a_v, b_u)
        
        // Case 1: b_v <= b_u
        int cnt1 = cnt_bit.query(b_idx);
        ll sum_a1 = sum_bit.query(b_idx);
        
        // Untuk case 1, kita butuh sum dari min(a_v, b_v) untuk semua v dengan b_v <= b_u
        // Kita simpan di BIT terpisah
        total += sum_a1; // Sementara, nanti kita koreksi
        
        // Case 2: b_v > b_u  
        int cnt2 = i - cnt1;
        total += (ll)cnt2 * min(a_val, b_val);
        
        // Update BIT untuk a_v
        cnt_bit.update(b_idx, 1);
        sum_bit.update(b_idx, a_val);
    }
    
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> S1 >> S2;
    
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    bfs(S1, a);
    bfs(S2, b);
    
    ll S_A = compute_sum_min(a);
    ll S_B = compute_sum_min(b);
    ll S_AB = compute_sum_min_ab();
    
    ll ans = S_A + S_B - S_AB;
    cout << ans << endl;
    
    return 0;
}
