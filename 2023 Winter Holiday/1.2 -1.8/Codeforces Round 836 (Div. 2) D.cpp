#include <iostream>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n & 1){//
            n ++;
            for(int i = n/2+1;i <= 3*n/2+1;i ++){
                if(i != n && i != n+1){
                    cout<<i<<' ';
                }
            }
            cout<<endl;
        }
        else{//构造 n/2 ~ 3n/2    2n*n/2
        
            for(int i = n/2;i <= 3*n/2;i ++){
                if(i != n)cout<<i<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}