#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 2e5;
bool used[N+5];

void shuf(vector<int>&ar){
	int n = ar.size();
	for(int i = 3; i < n; i++) ar[i] = rnd.next(1, N);

	// swap indices
	for(int i = 0; i < n; i++){
		int j = rnd.next(0, N) % n;
		swap(ar[i], ar[j]);
	}
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
		
    for(int i = 0; i < N; i++) used[i] = false;

    int n = rnd.next(1, N);
  	cout << n << '\n';

  	int roll = rnd.next(1, 200);
  	if(roll % 5 <= -1){// no answer
	  	for(int i = 0; i < n; i++){
	  		int a;
	  		do {
	  			a = rnd.next(1, N);
	  		} while(used[a]) ;
	  		used[a] = true;
	  		cout << a << " \n"[i==n-1];
	  	}
	  }
	  else {
	  	vector<int> ar(n);
	  	ar[0] = rnd.next(1, N);
	  	if(n >= 2) ar[1] = ar[0];
	  	if(n >= 3){
	  		if(roll % 5 == 3) ar[2] = ar[1];
	  		else ar[2] = rnd.next(1, N);
	  	}

	  	shuf(ar);
	  	for(int i = 0; i < n; i++){
	  		cout << ar[i] << " \n"[i==n-1];
	  	}
	  }
}


/*

*/