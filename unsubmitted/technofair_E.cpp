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

const int P = 53, MOD = 1e9+9;

void doumo_same_desu(){
    int n;
    string t;	
    cin >> n >> t;

    int T = t.size();
    int len;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());

    len = s[0].size() * n;

    vector<int> ppow(15), inv_ppow(15);
    ppow[0] = 1;
    for(int i = 1; i < 15; i++) {
        ppow[i] = ppow[i-1] * P % MOD;
    }

    vector<int> hashes;
    do {
        string ss = "";
        for(string&tmp : s) ss += tmp;
        
        // hitung hash value 
        int hs = 0;
        for(int i = 0; i < (int)ss.size(); i++){
            hs = (hs + (ss[i]-'a'+1) * ppow[i]) % MOD;
        }
        hashes.push_back(hs);

    }while(next_permutation(s.begin(), s.end()) && len <= T);

    map<int,bool> ada;
    for(int i : hashes) ada[i] = true;

    vector<int> ht(T+1);
    for(int i = 0; i < T; i++){
        ht[i+1] = (ht[i] + (t[i]-'a'+1) * ppow[i]) % MOD;
    }

    vector<int> res;
    for(int i = 0; i + len - 1 < T && len <= T; i++){
        int cur = (ht[i+len]-ht[i]+MOD)%MOD;
        cur *= inv(ppow[i],MOD);
        cur %= MOD;
        if(ada[cur]) res.push_back(i);
    }
    if(res.empty()){
        cout << "-1\n"; return ;
    }
    cout << res.size() << '\n';
    for(int i : res) cout << i << ' ';
    cout << '\n';
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	int tc = 1;
	// cin >> tc;
	while(tc--) doumo_same_desu();
}
/*
10
abcdefghijklmnopqrstuvwxyz
bcdefghijk
cdefghijkl
defghijklm
efghijklmn
fghijklmno
ghijklmnop
hijklmnopq
ijklmnopqr
jklmnopqrs
klmnopqrst


*/