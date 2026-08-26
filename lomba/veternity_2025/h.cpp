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

void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

//	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}

struct RabinKarp{
  static const int MOD = 1e9 + 9;
  int PP = 53;
  vector<int> H, P; // uses 1-base index
  string S;

  void init(string s, int _PP = 53){
    S = " " + s;
    PP = _PP;
    int sz = s.size();
    H = vector<int>(sz + 1);
    P = vector<int>(sz + 1);

    P[0]=1;
    for(int i = 1; i <= sz; i++){
        P[i] = (P[i-1] * PP) % MOD;
    }
    // calculate hash table for S
    for(int i = 1; i <= sz; i++){
        H[i] = (H[i-1] + (S[i]-'a'+1) * P[i]) % MOD;
    }
  }
  int get_hash(int l, int r){ // remember to use 1-based index
    int res = (H[r]-H[l-1]+MOD)%MOD;
    res *= inv(P[l], MOD);
    res %= MOD;
    return res;
  }
};
const int maxn = 2e5 +5;
void doumo_same_desu(){
	int n;
	string s;
	cin >> n >> s;
	
	RabinKarp hs;
	hs.init(s);

	int m;
	cin >> m;
	vector<pair<string, int>> d(m);
	for(int i = 0; i < m; i++){
		cin >> d[i].first;
		RabinKarp tmp; tmp.init(d[i].first);
		d[i].second = tmp.get_hash(1, (int)d[i].first.size());

		// cout << d[i].first << ' ' << d[i].second << "\n";
	}

	vector<pair<int,int>> pp;
	for(int i = 0; i < m; i++){
		int len = (int)d[i].first.size();
		for(int j = 0; j + len - 1 < n; j++){
			if(hs.get_hash(j + 1, j + len) == d[i].second) pp.push_back({j + 1, j + len});
		}
	}
	
	for(auto p : pp) cout << p.first << ' ' << p.second << "\n";


	sort(pp.begin(), pp.end(), [&](pair<int,int>a,pair<int,int>b){
		return a.second < b.second;
	});
	int dp[maxn] = {0};
	vector<int> rr;
	for(auto[l, r] : pp) rr.push_back(r);
	int cur = -1;
	for(int i = 0; i < n; i++){
		auto[l, r] = pp[i];
		int lb = lower_bound(rr.begin(), rr.end(), l) - rr.begin();
		lb--;
		if(lb >= 0) dp[r] = max({dp[r], cur, dp[lb] + (r - l + 1) * (r - l + 1)});
		else dp[r] = max({dp[r], cur, (r - l + 1) * (r - l + 1)});
		cur = max(dp[r], cur);
	}
	cout << cur << endl;



}

/*

*/
