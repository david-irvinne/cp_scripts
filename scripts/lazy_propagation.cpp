#include<iostream>
#include<iomanip>
#include<algorithm>
#include<random>
#include<chrono>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map> 
#include<set>
#include<climits>
using namespace std;
 
#define int long long
#define gcd __gcd
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
#define bpc(x) (__builtin_popcountll(x))
 
vector<int> tree, lz;
int n, q;
 
int segtree(int ql, int qr, int t = 1, int tl = 0, int tr = n - 1){
	if(lz[t]){
		tree[t] += lz[t];
		if(tl != tr){
			lz[2 * t] += lz[t] / 2;
			lz[2 * t + 1] += lz[t] / 2;
		}
		lz[t] = 0;
	}
	if(ql <= tl && tr <= qr) return tree[t];
	if(qr < tl || ql > tr) return 0;
	int mid = (tl + tr) / 2;
	return segtree(ql, qr, 2 * t, tl, mid) + segtree(ql, qr, 2* t + 1, mid + 1, tr);
}
 
void upd(int ql, int qr, int val, int t = 1, int tl = 0, int tr = n - 1){
	if(lz[t]){
		tree[t] += lz[t];
		if(tl != tr){
			lz[2 * t] += lz[t] / 2;
			lz[2 * t + 1] += lz[t] / 2;
		}
		lz[t] = 0;
	}
 
	if(ql <= tl && tr <= qr){
		tree[t] += val * (tr - tl + 1);
		if(tl != tr){
			lz[2 * t] += val * (tr - tl + 1) / 2;
			lz[2 * t + 1] += val * (tr - tl + 1) / 2;
		}
		return ;
	}
	if(qr < tl || ql > tr) return ;
	int mid = (tl + tr) / 2;
	upd(ql, qr, val, 2 * t, tl, mid);
	upd(ql, qr, val, 2 * t + 1, mid + 1, tr);
	tree[t] = tree[2 * t] + tree[2 * t + 1];
}
 
void solve(){
	cin >> n >> q;
	vector<int> tmp(n);
	for(int i = 0; i < n; i++) cin >> tmp[i];
	while(bpc(n) > 1){
		n++;
		tmp.push_back(0);
	}
	tree.resize(2 * n);
	lz.resize(2 * n);
	for(int i = 0; i < n; i++) tree[n + i] = tmp[i];
	for(int i = n - 1; i >= 1; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
 
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int l, r, val;
			cin >> l >> r >> val;
			upd(l-1, r-1, val);
		}
		else {
			int pos;
			cin >> pos;
			cout << segtree(pos-1,pos-1) << '\n';
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);
 
	int T = 1;
	// cin >> T;
	while(T--) solve();
}