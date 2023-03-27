#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    bool result = (n & (n-1)) == 0 ? true : false;
    cout<<result<<endl;

    int ans = __builtin_clz(n);
    cout<<ans<<endl;
    cout<<32 - ans<<endl;
    return 0 ;
}