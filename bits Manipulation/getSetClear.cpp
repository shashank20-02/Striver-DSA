#include<bits\stdc++.h>
using namespace std;

int main(){
    int n , i;
    cin>>n>>i;
    int getBit , set , clear;
    int mask = (1 << (i-1));
    getBit = (n & mask) != 0 ? 1 : 0;
    set = n | mask;
    clear= n & (~mask);
    cout<<getBit<<" "<<set<<" "<<clear<<endl;
    return 0 ;
}