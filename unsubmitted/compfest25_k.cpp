#include <bits/stdc++.h>

using namespace std;



#define int long long





signed main(){

    int n, h, w;

    cin >> n >> h >> w;

    vector<int> a(n);

    for(int i = 0; i < n; i++){

        cin >> a[i];

    }

    int l = 0, r = n;

    while(l < r){

        int mid = l + (r - l + 1) / 2;

        bool ok = 1;

        vector<int> temp(a.begin(), a.begin() + mid);

        sort(temp.rbegin(), temp.rend());

        int sum = 0;

        for(int i = 0; i < mid; i += w) sum += temp[i];

        if(sum > h) ok = 0;

        if(ok) l = mid;

        else r = mid - 1;

    }

    cout << l << endl;





}
