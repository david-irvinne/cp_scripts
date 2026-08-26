#include <bits/stdc++.h>

using namespace std;



#define int long long



const int maxn = 1e5 + 5;

vector<int> cnt(maxn, 0);





signed main() {



    int n;

    cin >> n;

    

    for(int i = 0; i < n; i++){

        int a, b;

        cin >> a >> b;

        cnt[a] += b;

    }

    vector<int> cntt(cnt.begin(), cnt.end());

    for(int i = 0; i < maxn - 2; i++){

        cnt[i + 1] += cnt[i] / 2;

        cnt[i] = cnt[i] & 1;

    }

    if(cnt[0] == 1){

        cout << "TIDAK" << endl;

        exit(0);

    }

    vector<int> temp(cnt.begin() + 1, cnt.end());

    n = temp.size();

    bool ok = 1;

    for(int i = 0; i < n; i++){

       if(cntt[i] == 0 and temp[i] > 0) {

            ok = 0;

            break;

        }

        cntt[i]--;

        cntt[i + 1] += cntt[i] / 2;

    }

    cout << (ok ? "YA\n" : "TIDAK\n");





    
