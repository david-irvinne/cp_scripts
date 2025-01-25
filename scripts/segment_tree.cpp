struct segtree{
  vector<int> tree;
  int n;
  segtree(int _n){
    n = _n;
    tree.resize(4 * n + 5);
  }
  void upd(int idx, int val, int t, int tl, int tr){
    if(tr < idx || idx < tl) return ;
    if(tl == tr){
      tree[t] = val;
      return ;
    }
    int mid = (tl + tr) / 2;
    upd(idx, val, 2 *t, tl, mid);
    upd(idx, val, 2 * t + 1, mid + 1, tr);
    tree[t] = tree[2 * t] + tree[2 * t + 1];
  }
  void upd(int idx, int val){
    return upd(idx, val, 1, 0, n - 1);
  }

  int range_sum(int ql, int qr, int t, int tl, int tr){
    if(ql <= tl && tr <= qr) return tree[t];
    if(ql > tr || tl > qr) return 0;
    int mid = (tl + tr) / 2;
    return range_sum(ql, qr, 2 * t, tl, mid) + range_sum(ql, qr, 2 * t + 1, mid + 1, tr);
  }
  int range_sum(int ql, int qr){
    return range_sum(ql, qr, 1, 0, n - 1);
  }
  void print(){
    for(int t = 1; t <= 2 * n; t++){
      dbg(t);
      dbg(tree[t]);
    }
    cout << '\n';
  }

};

void doumo_same_desu(){ 
  int n, q;
  cin >> n >> q;
  segtree st(n);
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    st.upd(i, x);
  }

  // st.print();

  while(q--){
    int t;
    cin >> t;
    if(t == 1){
      int k, u;
      cin >> k >> u;
      st.upd(k-1, u);
    }
    else {
      int a, b;
      cin >> a >> b;
      cout << st.range_sum(a-1, b-1) << '\n';
    }
  }
  // st.print();
}





////////////////////////
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