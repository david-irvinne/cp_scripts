// padded segment tree, merged with lazy propagation
template<typename T>
struct segment_tree {
//INGAT: kalau pake 1-based index, buat array source nya 1-based index, bukan segment tree nya.
  vector<T> tree, lz;
  int sz = 1;
  bool lazy_propagation = false;
  segment_tree(vector<T>&ar, bool lp = false){
    lazy_propagation = lp;

    int n = ar.size();
    while(sz < n) sz *= 2;
    tree.resize(2 * sz);
    if(lazy_propagation){
      lz.resize(2 * sz);
    }
    build(ar);
  }

  // TODO: merge behaviour between two nodes
  T merge(T a, T b){
    return a, b;
  }

  // TODO: fill this build function
  void build(vector<T>&ar){
    int n = ar.size();
    // isi leaf nya
    for(int i = 0; i < n; i++) tree[sz + i] = ar[i];
    // isi internal nodes 
    for(int i = sz - 1; i >= 1; i--) tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  }

  // TODO: change the default return value of out of range
  T range_query(int ql, int qr, int t, int tl, int tr){
    if(lazy_propagation && lz[t]){ // check kalau ada update di lz
      tree[t] += lz[t];            // ganti lz update nya kalau query nya bukan range sum
      if(tl != tr){
        lz[2 * t] += lz[t] / 2;
        lz[2 * t + 1] += lz[t] / 2;
      }
      lz[t] = 0;
    }

    if(ql <= tl && tr <= qr) return tree[t];
    if(tl > qr || ql > tr) return ;// put default outside value
    int mid = (tl + tr) / 2;
    return merge(range_query(ql, qr, 2 * t, tl, mid) , range_query(ql, qr, 2 * t + 1, mid + 1, tr));
  }

  T range_query(int ql, int qr){
    return range_query(ql, qr, 1, 0, sz - 1);
  }

  // TODO: updatenya increase apa change?
  void point_update(int idx, T new_val){
    idx += sz;
    tree[idx] = new_val;
    for(idx /= 2; idx >= 1; idx /= 2){
      tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }
  }

  // TODO: LAZY PROPAGATION, increase range atau update range?
  // CEK TIPE UPDATE-NYA: SUM? MAX? XOR? OR?
  void range_update(int ql, int qr, int val, int t, int tl, int tr){ if(lz[t]){ // check kalau ada update
      tree[t] += lz[t];
      if(tl != tr){
        lz[2 * t] += lz[t] / 2;           // HAPUS /2 kalau range-nya MAX QUERY
        lz[2 * t + 1] += lz[t] / 2;
      }
      lz[t] = 0;
    }

    if(ql <= tl && tr <= qr){
      tree[t] += val * (tr - tl + 1); // increase range
      if(tl != tr){
        lz[2 * t] += val * (tr - tl + 1) / 2;
        lz[2 * t + 1] += val * (tr - tl + 1) / 2;
      }
      return ;
    }
    if(qr < tl || ql > tr) return ;

    int mid = (tl + tr) / 2;
    range_update(ql, qr, val, 2 * t, tl, mid);
    range_update(ql, qr, val, 2 * t + 1, mid + 1, tr);
    tree[t] = merge(tree[2 * t] , tree[2 * t + 1]);
  }

  // implement lazy_propagation
  void range_update(int ql, int qr, int val){
    if(!lazy_propagation){
      cout << "ERROR: MUST IMPLEMENT LAZY PROPAGATION\n"; return ;
    }
    range_update(ql, qr, val, 1, 0, sz - 1);
  }
  void _print(){
    for(int i = 1; i < 2 * sz; i++){
      cout << i << ": " << tree[i] << '\n';
    }
  }
};


// ==============================================================================



// padded segment tree
template<typename T>
struct segment_tree {
//INGAT: kalau ma pake 1-based index, buat array source nya 1-based index, bukan segment tree nya.
 
  vector<T> tree;
  int sz = 1;
  segment_tree(vector<T>&ar){
    int n = ar.size();
    while(sz < n) sz *= 2;
    tree.resize(2 * sz);
    build(ar);
  }
  
  // TODO: fill this build function
  void build(vector<T>&ar){
    int n = ar.size();
    // isi leaf nya
    for(int i = 0; i < n; i++) tree[sz + i] = ar[i];
    // isi internal nodes 
    for(int i = sz - 1; i >= 1; i--) tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  }
  
  // TODO: merge behaviour between two nodes
  T merge(T&a, T&b){
    return a + b;
  }
  
  // TODO: change the default return value of out of range
  T range_sum(int ql, int qr, int t, int tl, int tr){
    if(ql <= tl && tr <= qr) return tree[t];
    if(tl > qr || ql > tr) return 0;
    int mid = (tl + tr) / 2;
    return range_sum(ql, qr, 2 * t, tl, mid) + range_sum(ql, qr, 2 * t + 1, mid + 1, tr);
  }
  T range_sum(int ql, int qr){
    return range_sum(ql, qr, 1, 0, sz - 1);
  }

  void point_update(int idx, T new_val){
    idx += sz;
    tree[idx] = new_val;
    for(idx /= 2; idx >= 1; idx /= 2){
      tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }
  }

  void _print(){
    for(int i = 1; i < 2 * sz; i++){
      cout << i << ": " << tree[i] << '\n';
    }
  }
};

// ==============================================================================

// unpadded segment tree
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

// ==============================================================================

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



