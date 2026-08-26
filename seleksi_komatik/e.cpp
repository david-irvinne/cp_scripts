#include<bits/stdc++.h>
using namespace std;

#define int long long
#define Int __int128_t
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
#define bpc(x) (__builtin_popcountll(x))

int bpow(int a, int b, long long mod=LLONG_MAX){
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

int x, y, step;

int dist(int a, int b){
	return abs(a) + abs(b);
}

string ans;

bool f(int a, int b, int k){
	if(k == step){
		return a == x && b == y;
	}

	int add = bpow(2, k);

	// kanan
	// if(dist(a + add, b) <= bpow(2, k + 1) - 1){
		ans += 'R';
		if(f(a + add, b, k + 1)) return 1;
		ans.pop_back();
	// }
	// kiri
	// if(dist(a - add, b) <= bpow(2, k + 1) - 1){
		ans += 'L';
		if(f(a - add, b, k + 1)) return 1;
		ans.pop_back();
	// }
	// atas
	// if(dist(a, b + add) <= bpow(2, k + 1) - 1){
		ans += 'U';
		if(f(a, b + add, k + 1)) return 1;
		ans.pop_back();
	// }
	// bawah
	// if(dist(a, b - add) <= bpow(2, k + 1) - 1){
		ans += 'D';
		if(f(a, b - add, k + 1)) return 1;
		ans.pop_back();
	// }
	return 0;
}

void solve(){	
	cin >> x >> y;

	step = 0;
	while(dist(x, y) > bpow(2, step) - 1) step++;
	dbg(step);
	if(step >= 15){
		cout << "-1\n";
		return ;
	}
	ans = "";
	if(f(0, 0, 0)){
		cout << ans << '\n';
	}
	else cout << -1 << '\n';

}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	int tc = 1;
	// cin >> tc;
	while(tc--) solve();
}
/*
-15 2
3 6


*/