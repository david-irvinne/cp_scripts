#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    long long mxN = 1000;

    long long a = rnd.next(1ll, mxN);
    long long b = rnd.next(1ll, mxN);
    long long c = rnd.next(1ll, mxN);
    long long d = rnd.next(1ll, mxN);
    long long e = rnd.next(1ll, mxN);
    long long f = rnd.next(1ll, mxN);
    long long x = rnd.next(1ll, mxN);

    int roll = rnd.next(1, 2000) ;
    if(roll % 5 <= 2){ // benar
        f = a * x + (b/c) * x + ((d-1)/e+1) * x;    

        cout << a << " " << b << " " << c << ' ';
        cout << d << " " << e << " " << f << endl;
    }   
    else { // salah
        cout << a << " " << b << " " << c << ' ';
        cout << d << " " << e << " " << f << endl;
    }

}
/*
158260522 877914575 602436426 24979445 1861648772 158260524

*/