// given an array with all numbers appearing twice except two numbers find out those numbers.

#include<bits\stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums){
    int xxor = 0 ;
    for(auto it : nums){
        xxor = xxor ^ it;
    }

    int cnt =0 ;
    while(xxor != 0){
        cnt++;
        xxor = xxor >> 1 ;
        if(xxor & 1)
            break;
    }

    vector<int>ans(2 , 0);
    for(auto it : nums){
        if(it & (1 << (cnt-1)))
            ans[0] = ans[0] ^ it;
        else 
            ans[1] = ans[1] ^ it;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n , 0);
    for(int i = 0 ; i<n;i++)
        cin>>arr[i];
    
    vector<int>ans = solve(arr);

    for(int i = 0 ;i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0 ;
}