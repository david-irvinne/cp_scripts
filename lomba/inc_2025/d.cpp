#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define int long long
int n, m;
vector<int> dijk(vector<vector<pair<int,int>>>& adj, int from){
    vector<int> res(n + 1, 1e18);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    res[from] = 0;
    pq.push({0, from});
    while(!pq.empty()){
        auto[a, b] = pq.top();
        pq.pop();
        if(a != res[b]) continue;
        for(auto [node, w] : adj[b]){
            if(res[node] > a + w){
                res[node] = a + w;
                pq.push({res[node], node});
            }
        }
    }
    return res;
}

signed main(){
    scanf("%lld%lld", &n, &m);
    vector<vector<pair<int,int>>> adj(n + 1), adj1(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        adj1[a].push_back({b, c + (c + 1) / 2});
        adj1[b].push_back({a, c + (c + 1) / 2});

    }
    vector<int> dp1 = dijk(adj, 1);
    vector<int> dp2 = dijk(adj1, 2);
    vector<int> dp3 = dijk(adj, 3);

    int ans = 1e18;
    for(int i = 1; i <= n; i++){
        if(dp1[i] == 1e18 or dp2[i] == 1e18 or dp3[i] == 1e18) continue;
        ans = min(ans, dp1[i] + dp2[i] + dp3[i]);
    }
    printf("%lld\n", ans);


}
