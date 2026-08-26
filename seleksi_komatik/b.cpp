#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll x, ll y, ll MOD){
	if(y == 0) return 1;
	if(y == 1) return x;
	ll z = power(x, y/2, MOD);
	z = (z*z)%MOD;
	if(y&1) z = (z*x)%MOD;
	return z;
}

// ll phi(ll n) {
//     ll result = n;
//     for (ll i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             while (n % i == 0)
//                 n /= i;
//             result -= result / i;
//         }
//     }
//     if (n > 1)
//         result -= result / n;
//     return result;
// }

int main(){
	//cout << power(4,100,100) << endl;
	
	ll n, k;
	cin >> n >> k;

	ll a[n];
	for(ll i = 0; i<n; i++) a[i] = i;
	
	ll cnt = 0;
	ll ans1 = 0, ans2 = 0;
	int loop = 0;
	while(1){
		// loop++;
		ans2 = 0;
		for(ll i = 0; i<n; i++){
			a[i] = power(a[i], k, n);
			//cout << a[i] << ' ';
			ans2 += a[i];
		}
		//cout << endl;
		//cout << ans1 << ' ' << ans2 << endl;
		if(ans1 == ans2){
			break;
		}
		else{
			cnt = 0;
		}
		ans1 = ans2;
	}
	cout << "loop : " << loop << "\n";
	cout << ans2 << endl;
	
	return 0;
}