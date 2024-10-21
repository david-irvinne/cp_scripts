#include<bits/stdc++.h>
using namespace std;

#define int long long
#define Int __int128_t
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;

int bpow(int a, int b, long long mod=LLONG_MAX){
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
vector<int> A;
vector<vector<int>> block;
int sq;

int cari(vector<int>&vec, int x){
	int res = - 1, sz = vec.size();
	for(int J = 1 << 15; J; J /= 2){
		if(res + J < sz && vec[res + J] < x) res += J;
	}
	return res + 1;
}

int qry(int l, int r, int v){ // l sampe r yang kurang dari v
	int k = 0;
	int lb = l / sq, rb = r / sq;

	if(lb == rb){
		for(int i = l; i <= r; i++){
			k += A[i] < v;
		}
		return k;
	}

	for(int i = l; i < (lb + 1) * sq; i++){
		k += A[i] < v;
	}
	for(int i = lb + 1; i <= rb - 1; i++){
		k += cari(block[i], v);
	}
	for(int i = rb * sq; i <= r; i++){
		k += A[i] < v;
	}
	return k;
}

void upd(int pos, int x){
	int old = A[pos];
	A[pos] = x;

	// ubah bilangan lama dari block[pos/sq] menjadi x
	int ppos = pos / sq;
	// cari posisinya dulu
	int idx = -1, sz = block[ppos].size();
	for(int J = 1 << 15; J; J /= 2){
		if(idx + J < sz && block[ppos][idx+J] <= old){
			idx += J;
		}
	}
	// ubah, di-shift, maximal O(sqrt(N)) 
	block[ppos][idx] = x;
	while(idx + 1 < sz && block[ppos][idx] > block[ppos][idx + 1]) {
		swap(block[ppos][idx] , block[ppos][idx + 1]);
		idx++;
	}
	while(idx - 1 >= 0 && block[ppos][idx] < block[ppos][idx - 1]) {
		swap( block[ppos][idx] , block[ppos][idx - 1]);
		idx--;
	}

	// cout << "New array: \n";
	// for(int i : block[ppos]) cout << i << ' ';
	// cout << '\n';
}

void solve(){
	int n, m, u;
	cin >> n >> m >> u;

	sq = sqrt(n) + 1;
	A.resize(n);
	block.resize(sq);
	for(int i = 0; i < n; i++){
		cin >> A[i];
		block[i / sq].push_back(A[i]);
	}
	for(auto&p : block){
		sort(p.begin(), p.end());
	}

	while(m--){
		int l, r, v, p;
		cin >> l >> r >> v >> p;
		l--; r--; p--;

		// jawab query
		int k = qry(l, r, v);
		// dbg(k);
		// update element pada index p
		upd(p, u * k / (r-l+1));
	}

	for(int i = 0; i < n; i++) cout << A[i] << '\n';
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	int tc = 1;
	// cin >> tc;
	while(tc--) solve();
}
/*

10 1 11
1
2
3
4
5
6
7
8
9
10
2 8 6 10

*/