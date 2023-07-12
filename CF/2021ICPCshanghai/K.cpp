#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n == 1 || n == 3)cout<<"Unlucky";
    else{
        if(n & 1){
            cout<<"010";
            n -= 3;
        }
        for(int cnt = 0;cnt < n/2;cnt ++){
            if(cnt & 1)cout<<"01";
            else cout<<"10";
        }
    }
    return 0;
}