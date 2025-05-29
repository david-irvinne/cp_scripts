// https://codeforces.com/contest/2057/problem/D

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define Int __int128_t
#define bpc(x) __builtin_popcountll(x)

#ifdef DEBUG
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
#else
#define dbg(x)
#endif

int bpow(int a, int b, long long mod=LLONG_MAX){
  int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

const int N = 2e5 + 5, INF = 1e12;

struct node {
  // min query, max query, max query - min query
  int L, R, ans;
};

// max idx is in r, (a_r - r) - (a_l - l)
struct segtree{
  node tree[4 * N];

  node merge(node left, node right){
    node res;
    res.L = min(left.L, right.L);
    res.R = max(left.R, right.R);
    res.ans = max({left.ans, right.ans, right.R - left.L});
    return res;
  }

  void update(int t, int tl, int tr, int pos, int val){
    if(tl > pos || tr < pos) return ;
    if(tl == tr){
      tree[t].L = val;
      tree[t].R = val;
      tree[t].ans = 0;
      return ;
    }
    int mid = (tl + tr) / 2;
    update(t * 2, tl, mid, pos, val);
    update(t * 2 + 1, mid + 1, tr, pos, val);
    tree[t] = merge(tree[2 * t], tree[2 * t + 1]);
  }

  node query(int t, int tl, int tr, int ql, int qr){
    if(ql <= tl && tr <= qr) return tree[t];
    if(ql > tr || tl > qr) return { INF, INF, -INF};
    int mid = (tl + tr) / 2;
    return merge( query(t * 2, tl, mid, ql, qr), query(t * 2 + 1, mid + 1, tr, ql, qr) );
  }
  void build(int n){
    for(int i = 0; i < 4 * n; i++){
      tree[i] = {INF, INF, -INF};
    }
  }
} st1;

// max idx is in l, (a_l + l) - (a_r + r)
struct segtree2{
  node tree[4 * N];

  node merge(node left, node right){
    node res;
    res.L = min(left.L, right.L);
    res.R = max(left.R, right.R);
    res.ans = max({left.ans, right.ans, left.R - right.L});
    return res;
  }

  void update(int t, int tl, int tr, int pos, int val){
    if(tl > pos || tr < pos) return ;
    if(tl == tr){
      tree[t].L = val;
      tree[t].R = val;
      tree[t].ans = 0;
      return ;
    }
    int mid = (tl + tr) / 2;
    update(t * 2, tl, mid, pos, val);
    update(t * 2 + 1, mid + 1, tr, pos, val);
    tree[t] = merge(tree[2 * t], tree[2 * t + 1]);
  }

  node query(int t, int tl, int tr, int ql, int qr){
    if(ql <= tl && tr <= qr) return tree[t];
    if(ql > tr || tl > qr) return { INF, INF, -INF};
    int mid = (tl + tr) / 2;
    return merge( query(t * 2, tl, mid, ql, qr), query(t * 2 + 1, mid + 1, tr, ql, qr) );
  }

  void build(int n){
    for(int i = 0; i < 4 * n; i++){
      tree[i] = {INF, INF, -INF};
    }
  }

} st2;

void doumo_same_desu(){ 

  int n, q;
  cin >> n >> q;
  st1.build(n);
  st2.build(n);
  vector<int>ar(n);
  for(int i = 0; i < n; i++){
    cin >> ar[i];
    st1.update(1, 0, n - 1, i, ar[i] - i);
    st2.update(1, 0, n - 1, i, ar[i] + i);
  }

  cout << max(st1.query(1, 0, n - 1, 0, n - 1).ans,
              st2.query(1, 0, n - 1, 0, n - 1).ans) << '\n';  

  while(q--){
    int p, x; cin >> p >> x;
    p--;
    st1.update(1, 0, n - 1, p, x - p);
    st2.update(1, 0, n - 1, p, x + p);

    cout << max(st1.query(1, 0, n - 1, 0, n - 1).ans,
                st2.query(1, 0, n - 1, 0, n - 1).ans) << '\n';  
  }
  
}
signed main(){
  ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(5);

  int tc = 1;
  cin >> tc;
  while(tc--) doumo_same_desu();
}
/*

*/
