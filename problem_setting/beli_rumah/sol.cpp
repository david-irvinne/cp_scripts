#include<bits/stdc++.h>
using namespace std;


int main(){
	int n, x;
	cin >> n >> x;
	int rumah[n];
	for(int i = 0; i < n; i++) {
		cin >> rumah[i];
	}

	sort(rumah, rumah + n);
	int res = 0;
	for(int i = 0; i < n; i++){
		if(rumah[i] <= x){
			x -= rumah[i];
			res++;
		}
	}
	cout << res << '\n';

}