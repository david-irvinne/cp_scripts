#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    const int N = 15, P = 1e9;
    int n = rnd.next(1, N), x = rnd.next(1, N);
    cout << n << ' ' << x << '\n';

    for(int i = 0; i < n; i++){
        cout << rnd.next(1, P) << " \n"[i==n-1];
    }
    for(int i = 0; i < x; i++){
        cout << rnd.next(1, P) << " \n"[i==x-1];
    }
}

/*


*/