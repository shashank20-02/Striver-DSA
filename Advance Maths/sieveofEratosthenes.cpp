#include<bits\stdc++.h>
using namespace std;

int N = 1e7 + 10 ;
vector<bool>primes(N , 1);

int main(){
    // Sieve computation
    primes[0] = primes[1] = false;
    for(int i = 2 ; i<N ; i++){
        if(primes[i]){
            for(int j = 2 * i ; j<=N ; j+=i)
                primes[j] = false;
        }
    }

    for(int i = 2 ; i<=100; i++){
        if(primes[i])
            cout<<i<<" ";
    }
    cout<<endl;
    return 0 ;
}