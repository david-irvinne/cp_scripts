#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define Int __int128_t

#ifdef DEBUG
#define dbg(x) cout << "["<< #x <<"] : "<< (x) <<endl;
#else
#define dbg(x)
#endif

int bpow(int a, int b, int64_t mod = LLONG_MAX) {
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

const int MOD = 1e9 + 7, MXN = 2e7 + 5;
int fac[MXN];

void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	fac[0] = 1;
	for(int i = 1; i < MXN; i++){
		fac[i] = i * fac[i-1];
		fac[i] %= MOD;
	}
	
  cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}

int C(int n, int k){
	return fac[n] * inv(fac[n - k] * fac[k] % MOD, MOD) % MOD;
}


void doumo_same_desu(){
	int n, k;
	cin >> n >> k;
	int K = k;
	int x = 0;
	while(k > 0){
		k -= (1ll << x);
		x++;
	}

	x = min(x, n);
	cout << x << ' ';

	// if(__builtin_popcountll(K) == 1 && K == 1ll << n){		
	// 	cout << fac[K] << '\n';
	// 	return ;
	// }

	int pos = 1ll << (x - 1);
	int N = K - 1;
	int R = pos - 1;

	int res = C(N, R);
	res *= fac[pos];
	res %= MOD;

	res *= fac[(1ll << n) - pos];
	res %= MOD;

	res *= 1ll << n;
	res %= MOD;
	res /= pos;

	cout << res << '\n';
}

/*

*/
