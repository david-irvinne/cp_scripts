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
const int MXN = 1e5 + 5;
int N, P;

struct T{
	int c, l, s, u, r;
}ship[MXN];

bool f(int w){
	Int total = 0;
	for(int i = 0; i < N; i++){
		Int res = 0;

		Int pergi = ship[i].l + ship[i].s + ship[i].u;
		Int pp = pergi + ship[i].r;

		Int trip = w / pp;
		res += trip * ship[i].c;

		if(w % pp >= pergi){
			res += ship[i].c;	
		}
		
		total += res;
	}
	return total >= P;
}

void doumo_same_desu(){
	cin >> N >> P;
	for(int i = 0; i < N; i++){
		cin >> ship[i].c >> ship[i].l >> ship[i].s;
		cin >> ship[i].u >> ship[i].r;
	}

	int res = 1e17;
	for(int J = 1ll << 58; J; J/=2){
		if(res - J >= 0 && f(res - J)) res -= J;
	}

	cout << res<< '\n';
}

/*

*/
