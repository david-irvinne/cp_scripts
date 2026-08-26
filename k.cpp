#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<pair<char,int>> ops; // 1-based
vector<array<int,16>> seg;  // segment tree: seg[node][v] = output when input=v

array<int,16> make_mapping(char t, int k){
    array<int,16> a;
    if(t == '+'){
        for(int v=0; v<16; ++v) a[v] = (v + k) % 16;
    } else { // assume 'x' means xor
        for(int v=0; v<16; ++v) a[v] = v ^ k;
    }
    return a;
}

array<int,16> compose(const array<int,16>& L, const array<int,16>& R){
    array<int,16> res;
    for(int v=0; v<16; ++v) res[v] = R[ L[v] ]; // R ∘ L
    return res;
}

void build(int node, int l, int r){
    if(l == r){
        seg[node] = make_mapping(ops[l].first, ops[l].second);
        return;
    }
    int mid = (l + r) >> 1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    seg[node] = compose(seg[node<<1], seg[node<<1|1]);
}

void update(int node, int l, int r, int pos, char t, int k){
    if(l == r){
        seg[node] = make_mapping(t, k);
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(node<<1, l, mid, pos, t, k);
    else update(node<<1|1, mid+1, r, pos, t, k);
    seg[node] = compose(seg[node<<1], seg[node<<1|1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin >> N >> Q)) return 0;
    ops.assign(N+1, {'+',0});
    for(int i=1;i<=N;++i){
        char t; int k;
        cin >> t >> k;
        ops[i] = {t, k};
    }
    seg.assign(4*N + 5, array<int,16>{});
    build(1, 1, N);

    for(int qi=0; qi<Q; ++qi){
        int pos; char t; int k;
        cin >> pos >> t >> k;
        update(1, 1, N, pos, t, k);
        cout << seg[1][0] << '\n'; // output for input 0
    }
    return 0;
}
