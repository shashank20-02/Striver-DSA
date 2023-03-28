#include<bits\stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;

    for(int i = 0 ; i<pow(2 , str.length()) ; i++){
        for(int j = 0 ; j<str.length() ; j++){
            if(i & (1 << j)){
                cout<<str[j];
            }
        }
        cout<<endl;
    }
    return 0 ;
}