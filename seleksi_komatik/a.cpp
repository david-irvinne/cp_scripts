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

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool prime(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (check_composite(n, a, d, r))return false;
    }
    return true;
}

void doumo_same_desu(){	
	string s;
	int k;
	cin >> s >> k;
	int sz = s.size();
	sort(s.begin(), s.end());

	set<int> res;
	do {
		// coba tiap substring dgn panjang k
		for(int i = 0; i + k - 1 < sz; i++){
			if(s[i] == '0') continue;
			int x = stoll(s.substr(i, k));

			if(prime(x)) res.insert(x);
		}
	} while(next_permutation(s.begin(), s.end()));
    cout << (int)res.size() <<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	int tc = 1;
	// cin >> tc;
	while(tc--) doumo_same_desu();
}
/*

*/