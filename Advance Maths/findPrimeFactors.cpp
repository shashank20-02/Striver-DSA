#include<bits\stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    set<int>primes;
    for(int i = 2 ; i * i <= n ; i++){
        while(n % i == 0){
            primes.insert(i);
            n /= i ;
        }
    }
    if(n > 1)
        primes.insert(n);
    
    for(auto prime : primes){
        cout<<prime<<" ";
    }
    cout<<endl;

    return 0 ;
}