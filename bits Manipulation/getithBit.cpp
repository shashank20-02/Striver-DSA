#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , i;
    cin>>n>>i;
    int getBit = bool(n & (1 << i));
    cout<<getBit<<endl;
    return 0 ;
}