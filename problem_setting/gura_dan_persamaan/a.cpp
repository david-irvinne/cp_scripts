// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define Int __int128_t
// #define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
// #define bpc(x) (__builtin_popcountll(x))

// int bpow(int a, int b, long long mod=LLONG_MAX){
// 	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
// }
// int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

// int a, b, c, d, e, f;

// int chk(int x){
//     return a * x + (b/c) * x + ((d-1)/e+1) * x;
// }

// void doumo_same_desu(){	
//     cin >> a >> b >> c >> d >> e >> f;

//     int x = 0;
//     for(int J = 1ll << 31; J; J /= 2){
//         if(chk(x + J) <= f) x += J;
//     }
//     cout << (chk(x) == f ? x : -1) << '\n';
// }   
// signed main(){
// 	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
// 	cout << fixed << setprecision(5);

// 	int tc = 1;
// 	// cin >> tc;
// 	while(tc--) doumo_same_desu();
// }
// /*

// */

#include<bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

int chk(int x){
    return a * x + (b/c) * x + ((d-1)/e+1) * x ;
}

int main(){
    cin >> a >> b >> c >> d >> e >> f;
    for(int i = 0; i <= 2e9; i++){
        if(chk(i) == f){
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
