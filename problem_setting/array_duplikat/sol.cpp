#include<bits/stdc++.h>
using namespace std;

#define int long long
// #define Int __int128_t
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
#define bpc(x) (__builtin_popcountll(x))

int bpow(int a, int b, long long mod=LLONG_MAX){
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

void doumo_same_desu(){	
	int n;
	cin >> n;
	int ar[n], cnt[2e5+5];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	for(int i = 0; i <= (int)2e5;i++){
		cnt[i]=0;
	}
	for(int i = 0; i < n; i++){
		cnt[ar[i]]++;
		if(cnt[ar[i]] == 2){
			cout << "YA\n";
			return ;
		}
	}
	cout << "TIDAK\n";
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

